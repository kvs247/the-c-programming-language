// Write a dunction escape(s, t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, convering
// escape sequences into the real characters.

#include <stdio.h>

void escape(char s[], char t[])
{
  int c;
  int i = 0;
  int j = 0;
  char esc = '\\';

  while ((c = s[i]) != '\0')
  {
    switch (c)
    {
    case '\a':
      t[j++] = esc;
      t[j] = 'a';
      break;
    case '\b':
      t[j++] = esc;
      t[j] = 'b';
      break;
    case '\e':
      t[j++] = esc;
      t[j] = 'e';
      break;
    case '\f':
      t[j++] = esc;
      t[j] = 'f';
      break;
    case '\n':
      t[j++] = esc;
      t[j] = 'n';
      break;
    case '\r':
      t[j++] = esc;
      t[j] = 'r';
      break;
    case '\t':
      t[j++] = esc;
      t[j] = 't';
      break;
    case '\v':
      t[j++] = esc;
      t[j] = 'v';
      break;
    case '\\':
      t[j++] = esc;
      t[j] = '\\';
      break;
    case '\'':
      t[j++] = esc;
      t[j] = '\'';
      break;
    case '\"':
      t[j++] = esc;
      t[j] = '"';
      break;
    case '\?':
      t[j++] = esc;
      t[j] = '?';
      break;
    default:
      t[j] = c;
      break;
    }

    i++;
    j++;
  }
  t[j] = '\0';
}

void unescape(char s[], char t[])
{
  int c;
  int i = 0;
  int j = 0;
  char esc = '\\';

  while ((c = s[i]) != '\0')
  {
    if (c == esc && s[i + 1] != '\0')
    {
      switch (s[i + 1])
      {
      case 'a':
        t[j] = '\a';
        break;
      case 'b':
        t[j] = '\b';
        break;
      case 'e':
        t[j] = '\e';
        break;
      case 'f':
        t[j] = '\f';
        break;
      case 'n':
        t[j] = '\n';
        break;
      case 'r':
        t[j] = '\r';
        break;
      case 't':
        t[j] = '\t';
        break;
      case 'v':
        t[j] = '\v';
        break;
      case '\\':
        t[j] = '\\';
        break;
      case '\'':
        t[j] = '\'';
        break;
      case '"':
        t[j] = '\"';
        break;
      case '?':
        t[j] = '\?';
        break;
      default:
        t[j] = c;
        break;
      }
      i++;
    }
    else
    {
      t[j] = c;
    }

    i++;
    j++;
  }
  t[j] = '\0';
}

int main()
{
  char s[] = "This\nis my\t string! It's\r\vgot\vsome\\\"escape\"\\characters.";
  char t[100];
  escape(s, t);
  printf("%s \n=>\n %s\n", s, t);

  printf("\n");

  char q[] = "This\\nis my\\t string! It\\'s\\r\\vgot\\vsome\\\\\\\"escape\\\"\\\\characters.";
  char r[100];
  unescape(q, r);
  printf("%s \n=>\n %s\n", q, r);

  return 0;
}