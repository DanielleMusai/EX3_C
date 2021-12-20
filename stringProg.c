#include <stdio.h>
#include <string.h>
#include "stringProglib.h"
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#define TXT 1024
#define WORD 30


int checkLetter(char c)
{
    int count = 0;
    if (c >= 'A' && c <= 'Z')
    {
      count += c - 64; 
    }
    else if (c >= 'a' && c <= 'z')
    {
         count += c - 96;
    }
   // printf("%d",count);
    return count;
}
int num(char *st)
{
    int len = strlen(st);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += checkLetter(st[i]);
    }
    return sum;
}
int isSign(char c)
{
    if ((c > '`' && c < '{') || (c > '@' && c < '[') )
    {// only letters 
        return 1;
    }
    else
    {
        return 0;
    }
}
void Gematria(char *word, char *text)
{
    int len = strlen(text);
    int start = 0;
    int flag=0;
    char *d = text;
      if (checkLetter(*d)!=0)
        {
    for(int i=0; i<len; i++){
        int sum = 0;
        start =i;
       if(isSign(text[i]))
        {
            while (text[start] && sum <  num(word))
            {
                sum = sum + checkLetter(text[start]);
                start++;
            }
            --start;
            if (sum  ==  num(word))
            {
                 if (flag)
                {
                    printf("~");
                }
               flag++;
                int j=i;
                  while(j<=start)
                  {
                    printf("%c", text[j]);
                    j++;
                }
            }
        }}
    }
    printf("\n");
}

int Atbash1(char a){
  //return the atbash value of the char

    if (a>= 'A' &&a<= 'Z')
        {
            return ('Z' - checkLetter(a)+1);
         }
         else if (a>='a' && a<='z')
         {
              return ('z'- checkLetter(a)+1);
        }
        return 0;
}
char *reverse(char *c)
{
    int j=0;
    char * reverse1 = ((char *)malloc(sizeof(char)*strlen(c)));
    for (int i = strlen(c)-1;i>=0;i--)
    {
         reverse1[j] = c[i];
         j++;
    }
    return reverse1;
}
 
char *atbashWord(char *word)//translate the word to atbash
{
    int len = strlen(word);
    int len2 = strlen(word);
    char* word1 =(char*)malloc(sizeof(char)*len);
    char *w = word;
    for(int i =0; i< len2; i++)
    {
       word1[i] = Atbash1(*w);
       w++;
        }

    return word1;
}


void Atbash(char *word, char *text)
{ 
    char* ans=(char*)malloc(sizeof(char)*780);
    int wlen= strlen(word);
    char *atword= atbashWord(word);
    char *revatword= atbashWord(reverse(word));
    int flag=0;
    char *d = text;
    int len = strlen (text);
    int start= 0;
      if (checkLetter(*d)!=0)
        {
    for(int i =0; i < len; i ++){
     int sum =0;
     start = i;
     if (isSign(text[i]))
     {
     while (text[start]&& sum < num(atword)){
             sum = sum + checkLetter((text[start]));
                start++;
            }
            --start;
            if (sum  ==  num(atword))// need to do a rev functuon
                { 
                 if (text[start] == atword[0] || text[start]== revatword[0]){  
                if (flag)
                {
                    printf("~");
                }
               flag++;
                 int j=i;
                  while(j<=start)
                  {
                    printf("%c", text[j]);
                    j++;
                 }
              }}
           }
        }
    }
    printf("\n");
}
        
         
              

int charForC(char c){
if (c > 'z' || c < 'A' ||  c < 'a' && c > 'Z')
{
    return 0;
}
else 
{
return 1;
   }
}


void Anagram(char *word, char *text){
 int len = strlen(text);
 int wlen = strlen(word);
 int c=0;
 char *d = text;
    int start = 0;
    int flag=0;
        if (checkLetter(*d)!=0)
        {
    for(int i=0; i<len; i++){
        int sum = 0;
        start =i;
            while (text[start] && sum <  num(word))
            {
                 if(charForC(text[start]))
                  {
                     sum =sum +checkLetter(text[start]);
                     start++;
                }
                else
                {
                sum = sum + num(word);
            }
            }
            --start;

            if (sum  ==  num(word))
            {
                c = 0;
            int s = (start -i);
                for (int j = 0; j < wlen; j++)
                 {
                    for (int k = 0; k <= s+1;k++)
                    {
                        if(word[j] == text[k+i])
                        {
                            c++;
                        }
                    }
                }
                if (c!=0 && wlen <=c)
                {
                    c++;
                if (flag)
                {
                    printf("~");
                }
                  flag ++;
                  int j=i;
                  while(j<=start)
                  {
                    printf("%c", text[j]);
                    j++;
                }
            
                }
            }    
            
       }
    
    }
}
    
int main()
{
    char word[WORD];
    char text[TXT] ;
    scanf("%s", word);
    char ch = 0;
    int i = 0;
    ch = getchar();
    if (!(ch == ' ' || ch == '\t' || ch == '\n'))
    {
        word[i] = ch;
        ch = getchar();
    }
    i = 0;
    ch = getchar();
    do
    {
        text[i] = ch;
        i++;
        ch = getchar();
    } while (ch != '~');
    printf("Gematria Sequences: ");
    Gematria(word, text);
    printf("Atbash Sequences:%c",32);
    Atbash(word,text);
    printf("Anagram Sequences: ");
    Anagram(word,text);
    return 0;
}
