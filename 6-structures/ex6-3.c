// Write a cross-referencer that prints a list of all words in a document, and,
// for each word, a list of the line numbers on which it occurs. Remove noise
// words like "the", "and", and so on.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *, int, int);
void treeprint(struct tnode *, int);
int getword(char *, int);

struct tnode
{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
  int linesi;
  int lines[];
};

/* word frequency count */
int main()
{
  int nlines = 1;
  char word[MAXWORD];
  while (getword(word, MAXWORD) != EOF)
  {
    if (word[0] == '\n')
      nlines++;
  }

  struct tnode *root;
  root = NULL;

  int line = 1;
  freopen(NULL, "r", stdin);
  printf("nlines: %d\n", nlines);
  while (getword(word, MAXWORD) != EOF)
  {
    // printf("%s\n", strcmp(word, "\n") == 0 ? "\\n" : word);
    if (word[0] == '\n')
    {
      line++;
      // printf("line: %d\n", line);
    }
    if (isalpha(word[0]))
      root = addtree(root, word, line, nlines);
  }
  treeprint(root, nlines);
  return 0;
}

struct tnode *talloc(int);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line, int arrSize)
{
  int cond;

  if (p == NULL) /* a new word has arrived */
  {
    p = talloc(arrSize); /* make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
    p->lines[0] = line;
    p->linesi = 1;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
  {
    p->count++; /* repeated word */
    if (p->lines[p->linesi - 1] != line)
      p->lines[p->linesi++] = line;
  }
  else if (cond < 0)
    p->left = addtree(p->left, w, line, arrSize); /* less than into left subtree */
  else
    p->right = addtree(p->right, w, line, arrSize); /* greater than into right subtree */
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p, int nlines)
{
  if (p != NULL)
  {
    int i;
    treeprint(p->left, nlines);
    printf("%4d %s [", p->count, p->word);
    for (i = 0; i < nlines; i++)
    {
      int line = p->lines[i];
      if (line == 0)
        break;
      printf("%s%d", i == 0 ? "" : " ", line);

    }
    printf("]\n");
    treeprint(p->right, nlines);
  }
}


/* talloc: make a tnode */
struct tnode *talloc(int arrSize)
{
  return (struct tnode *) malloc(sizeof(struct tnode) + arrSize * sizeof(int));
}

/* getword: get next word or charcter from input */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    if (c == '\n')
    {
      *w++ = '\n';
      *w = '\0';
      return word[0];
    }
  if (c != EOF)
    *w++ = c;
  if (!isalpha(c))
  {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch()))
    {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp;          /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}