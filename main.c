#include <stdio.h>
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

int main() {
    printf("Welcome to our movie database\n");
    printf("Please choose one of the following options:\n");
    printf("i. Insert a new movie\n");
    printf("s. Search for a movie\n");
    printf("u. Update a movie\n");
    printf("e. Delete a movie\n");
    printf("p. Print all movies\n");
    printf("q. Quit\n");
    char choice;
    scanf("%c", &choice);
    switch (choice) {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'e':
            erase();
            break;
        case 'p':
            print();
            break;
        case 'q':
            quit();
            break;
        default:
            printf("Please enter a valid option");
            break;
    }
    return 0;
}

void insert() {
    int code_m;
    int flag = 0;
    printf("Enter code: ");
    scanf("%d", &code_m);
        for (int i = 0; i <= m_counter ; i++){
            if (mov_array[i].code == code_m){
                printf("Code already exists");
                flag = 1;
                break;
            }
            
        }
        if(m_counter==99 && flag != 1){
            printf("The array is full, you can't insert any more moovies");
            flag = 1;
        }
        if (flag == 0){
            mov_array[code_m].code = code_m;
            printf("Enter title: ");
            scanf("%s", &mov_array[code_m].title);
            printf("Enter year: ");
            scanf("%d", &mov_array[code_m].year);
            m_counter++;
            printf("Movie inserted successfully");
        }
}

void search(){
    int code_s;
    printf("Enter code to find: ");
    scanf("%d", &code_s);
    for (int i = 0; i <= m_counter ; i++){
        if (mov_array[i].code == code_s){
            printf("Movie found\n");
            printf("Code: %d\n", mov_array[i].code);
            printf("Title: %s\n", mov_array[i].title);
            printf("Year: %d\n", mov_array[i].year);
            break;
        } else if (i==m_counter) {
            printf("Cannot find the movie, please enter the correct number next time!!");
            break;
        }
        
    }
}

void update(){
    int code_u;
    printf("Enter code for movie update: ");
    scanf("%d", &code_u);
    for (int i = 0; i <= m_counter ; i++) {
        if (mov_array[i].code == code_u) {
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
    for (int i = 0; i <= m_counter; i++) {
        if (mov_array[i].code == code_e) {
            mov_array[i].code = mov_array[m_counter].code;
            mov_array[i].title[title_size] = mov_array[m_counter].title[title_size];
            mov_array[i].year = mov_array[m_counter].year;
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
    printf("Here is a list of all movies:\n");
    for (int i = 0; i <= m_counter; i++) {
        printf("Code: %d\n", mov_array[i].code);
        printf("Title: %s\n", mov_array[i].title);
        printf("Year: %d\n", mov_array[i].year);
    }
}

void quit(){
    printf("Thank you for using our program please give us a 10/10 score on this project :)\n");
    quit();
}