#include <stdlib.h>

#ifndef MAIN_H
#define MAIN_H

char command[8];

// this is used in a switch statement later
int magicnum;

// This would be stored in comlist.h for adven
char comlist[6][10] =
  {
   "foo",
   "bar",
   "foobar",
   "corge",
   "xyzzy",
   "help"
  };

int input(command)
{
  scanf("%s", command);
  compare(command);
  return 0;
}

int compare(command)
{
  for (int loopmax = 0; loopmax < 6; loopmax++)
    {
      if (strcmp(command, comlist[loopmax]) == 0)
	{
	  magicnum = loopmax;
	  execute(magicnum);
	}
    }
  return 0;
}

int execute(magicnum)
{
  printf("You said ");
  switch(magicnum)
    {
    case 0:
      printf("foo\n");
      break;
    case 1:
      printf("bar\n");
      break;
    case 2:
      printf("foobar\n");
      break;
    case 3:
      printf("corge\n");
      break;
    case 4:
      printf("xyzzy\n");
      break;
    case 5:
      printf("help\n");
      break;
    default:
      printf("Uh oh\n");
      break;
    }
  return 0;
}

#endif
