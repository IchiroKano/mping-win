#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define BUFSIZE 64

int main(int argc, char *argv[])
{
  FILE *fp;
  int i=0;
  int j=0;
  int intMax=0;
  char strCmd[BUFSIZE];
  char strBuf[BUFSIZE];
  char strTemp[BUFSIZE];
  char strResult[BUFSIZE];
  char *token;
  time_t t;

  if( argc < 2 ) {
    printf( " Syntax: mping <IPaddress1> <IPaddress2> ..\n version 1.0\n" );
    exit(-1);
  }

  intMax = argc - 1;
  printf(" -----------------------------------------------\n");
  printf(" A mping targets %d IP address: [msec]\n", intMax);
  printf(" -----------------------------------------------\n");


  do {
    /* To print date, time and IP addresses */
    time(&t);
    if( j == 0 ) {
      printf( "  %s", ctime(&t));
      for( i = 0; i < intMax; i++ ) {
        printf("%16s", argv[i+1]);
      }
      printf("\n");
    }
    if(j++ > 10) j=0;

    /* To throw ping */
    strcpy( strResult, "" );
    for ( i = 0; i < intMax; i++ ) {

      snprintf(strCmd, BUFSIZE, "ping -n 1 %s", argv[i+1]);
      if((fp = popen(strCmd, "r")) == NULL) {
        printf("Can not exec ping. ");
        return -1;
      }
      strcpy( strTemp, "NG");
      do {
        token = fgets(strBuf, BUFSIZE, fp);
        if( strstr( strBuf, "TTL=") != NULL ) {
          strcpy( strTemp, strBuf );
          break;
        }
      } while( token != NULL );
      pclose(fp);

      strcpy( strResult, "" );
      if( strTemp[0] != 'N' ) {
        token = strtok( strTemp, " " );
        while( token != NULL ) {
          token = strtok( NULL, " " );
          /*printf( "[%s]", token );*/
          if( strstr( token, "ms" ) != NULL ) {
            printf( "%16s", token );
            break;
          }
        }
      } else {
        printf( "      *** NG ***" );
      }
    }
    printf("\n");
    sleep(1);
  } while( 1 );

  return 0;
}

