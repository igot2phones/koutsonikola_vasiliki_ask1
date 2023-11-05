#include <stdio.h>
#include <stdlib.h> // gia tin exit(0); stin void quit();
#define title_size 25

int m_counter = 0;
int allocation_meter = 0;


struct movie {
    int code; // edw o kwdikos tis tainias
    char title[title_size]; // edw to onoma tis tainias
    int year; // edw h xrwnia tis
};

struct movie *N; // metabliti pointer pou dixnei stin struct movie

void insert();
void search();
void memory_allocation(); //nea synartisi gia na min alazw pola ston kwdika pou egrapsa
void update();
void erase();
void print();
void quit();

//struct movie mov_array[STR_SIZE]; Deprecated for part 2
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

void memory_allocation(){
    if (m_counter==0){ // kanw alocate tis 4 prwtes theseis
        N = (struct movie*) malloc(4 * sizeof(struct movie)); //orizv me tin malloc ta prwta 4 movie
        allocation_meter = allocation_meter + 4; // metritis allocations 
        if (N == NULL) { // typiko check
            printf("Memory allocation failed");
            exit(EXIT_FAILURE); //oops
        }
        
    } else if (allocation_meter <= m_counter){ // allocation me realloc gia parapanw apo 4 tainies
        N = (struct movie*) realloc(N, (allocation_meter+1) * sizeof(struct movie));
        if (N == NULL) { // typiko check
            printf("Memory allocation failed");
            exit(EXIT_FAILURE); //oops
        }
        allocation_meter = allocation_meter + 1; // metritis allocations 
    }
}

void insert() { 
    memory_allocation();
    int code_m;
    int flag = 0; //dowlevw thn flag san diakopti me ta if statments gia na kserei to programma ti na kanei
    printf("Enter code: ");
    scanf(" %d", &code_m);
    while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima sto fgets(N[m_counter].title, title_size, stdin);
        for (int i = 0; i < m_counter ; i++){  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
            if (N[i].code == code_m){
                printf("Code already exists\n");
                flag = 1;
                break;
            }
            
        }

        // autos o kwdikas einai Deprecated gia tin askisi 2

        //if(m_counter==99 && flag != 1){ //an ftasei sto telos kai den exei brei tipota
        //    printf("The array is full, you can't insert any more moovies\n");
        //    flag = 1;
        //}


        if (flag == 0){ //an telika den to brei tha kanei eisagwgh 
            N[m_counter].code = code_m;
            printf("Enter title: ");
            fgets(N[m_counter].title, title_size, stdin);
            printf("Enter year: ");
            scanf("%d", &N[m_counter].year);
            m_counter++;
            printf("Movie inserted successfully\n");
            
        }
    return;
}

void search(){ //bazw klasika ton elenxo gia ton kwdiko me tin loopa kai to if, if else
    int code_s;
    int flag = 0; // an brikr thn tainia 
    printf("Enter code to find: ");
    scanf("%d", &code_s);
    for (int i = 0; i < m_counter ; i++){  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        if (N[i].code == code_s){
            printf("Movie found\n\n");
            printf("Code: %d\n\n", N[i].code);
            printf("Title: %s\n", N[i].title);
            printf("Year: %d\n", N[i].year);
            flag = 1; // thn brike
            break;
        }
    }
    if (flag == 0){
        printf("Cannot find the movie, please enter the correct number next time!!");
    }
    
}

void update(){ //bazw klasika ton elenxo gia ton kwdiko me tin loopa kai to if, if else 
    int code_u;
    int flag = 0;
    printf("Enter code for movie update: ");
    scanf("%d", &code_u);
    while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima sto line 126
    for (int i = 0; i < m_counter ; i++) {  //edw basw n-1 giati to index jekina apo 0 kai oxi 1 ( < )
        if (N[i].code == code_u) {
            printf("Enter new title: ");
            fgets(N[i].title, title_size, stdin);
            printf("Enter new year: ");
            scanf("%d", &N[i].year);
            printf("Movie updated");
            flag = 1;
            break; 
        }
    }
    if (flag == 0){
        printf("Cannot find the movie, please enter the correct number next time!!");
    }
    
}

void erase(){
    int code_e;
    int flag = 0;
    printf("Give me the code of the movie you want to delete: ");
    scanf("%d", &code_e);
    for (int i = 0; i < m_counter; i++) {  //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        if (N[i].code == code_e) {
            N[i] = N[m_counter-1];
            m_counter--;
            N = realloc(N, m_counter * sizeof(struct movie)); // realoc gia na mikrinw to allocation
            allocation_meter--;
            printf("Movie deleted");
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("Cannot find the movie, please enter the correct number next time!!");
    }
    
}

void print(){
    printf("Here is a list of all movies:\n\n");
    for (int i = 0; i < m_counter; i++) {   //edw basw n-1 giati to index jekina apo 0 kai oxi 1
        printf("Code: %d\n\n", N[i].code);
        printf("Title: %s\n", N[i].title);
        printf("Year: %d\n", N[i].year);
    }
}

void quit(){
    printf("Thank you for using our program please give us a 10/10 score on this project :)\n");
    free(N);
    // printf("debug : teleiwses mia kai kalh :)\n");
    exit(0); // teleionei to programma 
}
