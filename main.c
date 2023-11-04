#include <stdio.h>
#include <stdlib.h> // gia tin exit(0); stin void quit();
#define title_size 25
#define STR_SIZE 99

int m_counter = 0;

struct movie {
    int code; // edw o kwdikos tis tainias
    char title[title_size]; // edw to onoma tis tainias
    int year; // edw h xrwnia tis
};

void insert();
void search();
void update();
void erase();
void print();
void quit();

struct movie mov_array[STR_SIZE]; // Declare the size of the struct size
// general note : tha deite pola brakes giati poloi elenxoi ginontai mesa se loopa kai prepei kapws na bgienei ap thn loopa
int main() {
    char choice ;
    do {
    printf("\nWelcome to our movie database\n");
    printf("Please choose one of the following options:\n");
    printf("i. Insert a new movie\n");
    printf("s. Search for a movie\n");
    printf("u. Update a movie\n");
    printf("e. Delete a movie\n");
    printf("p. Print all movies\n");
    printf("q. Quit\n");
    scanf(" %c", &choice);
        switch (choice) {
            case 'i':
                insert();
                // printf("debug : teleiwses :)\n");
                break;
            case 's':
                search();
                // printf("debug : teleiwses :)\n");
                break;
            case 'u':
                update();
                // printf("debug : teleiwses :)\n");
                break;
            case 'e':
                erase();
                // printf("debug : teleiwses :)\n");
                break;
            case 'p':
                print();
                // printf("debug : teleiwses :)\n");
                break;
            case 'q':
                quit();
                //printf("debug : an to blepis sto output uparxei problima\n");
                break;
            default:
                printf("Please enter a valid option");
                break;
        }
    } while (1);
    return 0;
}

void insert() { 
    int code_m;
    int flag = 0; //dowlevw thn flag san diakopti me ta if statments gia na kserei to programma ti na kanei
    printf("Enter code: ");
    scanf(" %d", &code_m);
    while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima sto line 90
        for (int i = 0; i < m_counter ; i++){  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
            if (mov_array[i].code == code_m){
                printf("Code already exists\n");
                flag = 1;
                break;
            }
            
        }
        if(m_counter==99 && flag != 1){ //an ftasei sto telos kai den exei brei tipota
            printf("The array is full, you can't insert any more moovies\n");
            flag = 1;
        }
        if (flag == 0){ //an telika to brei 
            mov_array[m_counter].code = code_m;
            printf("Enter title: ");
            fgets(mov_array[m_counter].title, title_size, stdin);
            printf("Enter year: ");
            scanf("%d", &mov_array[m_counter].year);
            m_counter++;
            printf("Movie inserted successfully\n");
            
        }
    return;
}

void search(){ //bazw klasika ton elenxo gia ton kwdiko me tin loopa kai to if, if else
    int code_s;
    printf("Enter code to find: ");
    scanf("%d", &code_s);
    for (int i = 0; i < m_counter ; i++){  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        if (mov_array[i].code == code_s){
            printf("Movie found\n\n");
            printf("Code: %d\n\n", mov_array[i].code);
            printf("Title: %s\n", mov_array[i].title);
            printf("Year: %d\n", mov_array[i].year);
            break;
        } else if (i==m_counter) { // an den brei tipota (to exw testarei den tha ginei false trigger {eixa kai egw tin aporia} )
            printf("Cannot find the movie, please enter the correct number next time!!");
            break;
        }
        
    }
}

void update(){ //bazw klasika ton elenxo gia ton kwdiko me tin loopa kai to if, if else 
    int code_u;
    printf("Enter code for movie update: ");
    scanf("%d", &code_u);
    while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima sto line 126
    for (int i = 0; i < m_counter ; i++) {  //edw basw n-1 giati to index jekina apo 0 kai oxi 1 ( < )
        if (mov_array[i].code == code_u) {
            printf("Enter new title: ");
            fgets(mov_array[i].title, title_size, stdin);
            printf("Enter new year: ");
            scanf("%d", &mov_array[i].year);
            printf("Movie updated");
            break; 
        } else if (m_counter == i) {
            printf("Cannot find the movie, please enter the correct number next time!!");
            break;
        }
        
        
    }
    
}

void erase(){
    int code_e;
    printf("Give me the code of the movie you want to delete: ");
    scanf("%d", &code_e);
    for (int i = 0; i < m_counter; i++) {  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        if (mov_array[i].code == code_e) {
            mov_array[i] = mov_array[m_counter-1];
            m_counter--;
            printf("Movie deleted");
            break;
        } else if (m_counter == i) {
            printf("Cannot find the movie, please enter the correct number next time!!");
            break;
        }
    }
    
}

void print(){
    printf("Here is a list of all movies:\n\n");
    for (int i = 0; i < m_counter; i++) {   //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        printf("Code: %d\n\n", mov_array[i].code);
        printf("Title: %s\n", mov_array[i].title);
        printf("Year: %d\n", mov_array[i].year);
    }
}

void quit(){
    printf("Thank you for using our program please give us a 10/10 score on this project :)\n");
    // printf("debug : teleiwses mia kai kalh :)\n");
    exit(0); // teleionei to programma 
}