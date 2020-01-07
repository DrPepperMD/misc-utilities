#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "misc.h"

// Whats nessecariy(? I can't spell :P) to make a functional prompt that is
// simple enough for a 3 year old

// Your command
char command[20];

bool exitprompt = false;

int commandinput()
{
  printf("%s@comprompt:~$ ", getenv("USER")); // so it looks cool
  scanf(" %[^\n]s", command);
  cmpcommand(command);
  return 0;
}

int cmpcommand(command)
{
  if (strcmp(command, "foo") == 0)
    {
      system("ls /");
    }
  else if (strcmp(command, "bar") == 0)
    {
      system("ls ~/");
    }
  else if (strcmp(command, "foobar") == 0)
    {
      system("ls ~/ -R");
    }
  // this is just a personnal thing, it's to make life a bit easier
  else if (strcmp(command, "edit") == 0)
    {
      int editor;
      printf("What is your editor of choice?\navalible choices:\n");
      printf("Nano [1] (may not work correctly)\nGNU Emacs [2]\n");
      scanf("%d", &editor);
      if (editor == 1)
	{
	  system("nano");
	}
      else if (editor == 2)
	{
	  system("emacs");
	}
      else
	printf("int not recognised...\n");
    }
  else if (strcmp(command, "reset") == 0)
    {
      system("clear");
      about();
    }
  else if (strcmp(command, "about") == 0)
    {
      about();
    }
  else if (strcmp(command, "help") == 0)
    {
      // Oh may our lord and saviour External Function To Hide The Bloat save us!
      help();
    }
  else if (strcmp(command, "exit") == 0)
    {
      exitprompt = true;
    } 
  else
    {
      // Default result, simple error message with a cute little beep
      // I like the BASH shell a lot so I made it look like it (thx Brian Fox!)
      printf("comprompt- \"%s\" is not a valid command...\n\a", command);
      return 0;
    }
}
