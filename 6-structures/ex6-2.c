// Write a program that reads a C program and prints in alphabetical order each
// group of variable names that are identical in the first 6 characters, but
// different somewhere thereafter. Don't count words within strings and
// comments. Make 6 a parameter that can be set from the command line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode
{
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

/* word frequency count */
int main(int argc, char *argv[])
{
  struct tnode *root;
  char word[MAXWORD];
  int n = 6;
  int lastc = -1;
  int inSLComment = 0;
  int inMLComment = 0;
  int inString = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    n = (*argv)[1] - '0';

  char firstNWord[n];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
  {
    char c = word[0];

    // start of comment or string
    if (lastc == '/' && c == '/')
      inSLComment = 1;
    else if (lastc == '/' && c == '*')
      inMLComment = 1;
    else if (!inString && c == '\"')
      inString = 1;
    // end of comment or string    
    else if (inSLComment && c == '\n')
      inSLComment = 0;
    else if (inMLComment && lastc == '*' && c == '/')
      inMLComment = 0;
    else if (inString && c == '\"' && lastc != '\\')
      inString = 0;

    if (!inSLComment && !inMLComment && !inString && isalpha(c))
    {
      strncpy(firstNWord, word, n);
      root = addtree(root, firstNWord);
    }

    lastc = c;
  }
  treeprint(root);
  return 0;
}

struct tnode *talloc(void);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) /* a new word has arrived */
  {
    p = talloc(); /* make a new node */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
    p->count++; /* repeated word */
  else if (cond < 0)
    p->left = addtree(p->left, w); /* less than into left subtree */
  else
    p->right = addtree(p->right, w); /* greater than into right subtree */
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
  if (p != NULL)
  {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
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
  // printf("c: %d (%c)\n", c, c);
  if (c != EOF)
    *w++ = c;
  if (c == '\n')
    return c;
  if (!isalpha(c))
  {
    *w = '\0';
    return c;
  }
  for (; --lim > 0; w++)
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