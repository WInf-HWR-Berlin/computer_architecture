#include <stdio.h>

int main(void) {
    char *s = "Hi!";
    printf("%s\n", s); //prints whole s (String until it finds \0)
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);
    printf("%c\n", s[4]);
    for (int i = 5; i < 20; i++) {
        printf("%c\n", s[i]); // prints the first 5 characters of s
    }
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    
    char *p = &s[0];
    printf("%p\n", s);
    printf("%p\n", p);

    char c = s[0];
    char *p2 = &c;
    printf("%p\n", p2);
    
    printf("%p\n", &s); //pointer to the array (also works with just s
    //instead of &s because %p tells printf to print a pointer)
    printf("%p\n", &s[0]); //
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    typedef char* string;
    // typedef char *string; would create a new type string 
    // string s="Hi!" --> compiler macht automatisch die Allokation etc. string ist synonym zu char*
    string s2 = "Hi!";
    printf("%c\n", s2[0]);
    printf("%c\n", s2[1]);
    printf("%c\n", s2[2]);

    printf("%c\n", *s2);
    printf("%c\n", *(s2+1));
    printf("%c\n", *(s2+2));
    
    int numbers[] = {1,2,3,4,5};
    printf("%i\n", *numbers); //geht weil man array numbers als synonym fuer Adresse auf erstes Element des arrays behandeln kann
    printf("%i\n", *(numbers+1)); //Hinweis: Wir mussten nicht +4 machen obwohl es 4 bytes lang ist - compiler kuemmert sich drum
    printf("%i\n", *(numbers+2));
    printf("%i\n", *(numbers+3));
    printf("%i\n", *(numbers+4));
    
    printf("%p\n", &numbers[0]);
    printf("%p\n", &numbers[1]);
    printf("%p\n", &numbers[2]);
    printf("%p\n", &numbers[3]);
    printf("%p\n", &numbers[4]);
    printf("_____________\n");
    printf("%p\n", numbers);
    printf("%p\n", numbers+1);
    printf("%p\n", numbers+2);
    printf("%p\n", numbers+3);
    printf("%p\n", numbers+4);
    //typedef struct{
        
    //}   
}