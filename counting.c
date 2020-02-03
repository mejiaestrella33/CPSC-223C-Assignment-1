#include <stdio.h>

#define OUT 0
#define IN 1



int main(int argc, const char * argv[]) {
  long nc = 0;
  int curnc = 0;
  long nl = 0;
  long nw = 0;

  int words[25];
  for(int i = 0; i < 25; i++){
	words[i] = 0;
  }


  int c = getchar();

  int state = OUT;

  while (c != EOF){
	if( c != '\n' && c != ' ' && c != '\t'){
   	++ nc;
   	++curnc;

	}

	else if (c == '\n')
	{ ++ nl; }

	else { }

	if ( c == ' ' || c == '\n' || c == '\t'){
  	state = OUT;

	}
	else if ( state == OUT){
  	state = IN;
  	nw++;
  	printf("%d\n", curnc);
  	++words[curnc-1];
  	curnc = 0;

	}

	c = getchar();
  }

  words[0]--;


  printf("%ld chars and %ld lines and %ld words\n" , nc, nl, nw);

// printing horizontally
  for ( int i = 0; i < 25; i ++ ){
	printf("%d : ", i + 1);

	for (int j = 0; j <= (words[i] -1); j++){
  	printf( "*");
	}

	printf("\n");
  }

//printing vertically

printf("\n===================================================================\n");
  for (int i = 0; i < 16; i++){
    printf("%d:\t", i+1);
  }
printf("\n===================================================================\n");

for(int j = 0;  j < 16; j++){

  for ( int i = 0; i < 16; i ++ ){
    if(words[i] > j+1){
      printf( "*\t");
    }
  }
  printf("\n");
}

  return 0;
}
