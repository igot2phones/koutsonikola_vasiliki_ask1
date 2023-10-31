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

struct movie std_array[STR_SIZE]; // Declare the size of the struct size

int main() {
    return 0;
}

void insert() {
    int code_m;
    int flag = 0;
    printf("Enter code: ");
    scanf("%d", &code_m);
        for (int i = 0; i <= m_counter ; i++){
            if (std_array[i].code == code_m){
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
            std_array[code_m].code = code_m;
            printf("Enter title: ");
            scanf("%s", std_array[code_m].title);
            printf("Enter year: ");
            scanf("%d", &std_array[code_m].year);
            m_counter++;
        }
}

void search(){
    int code_s;
    printf("Enter code to find: ");
    scanf("%d", &code_s);
    for (int i = 0; i <= m_counter ; i++){
        if (std_array[i].code == code_s){
            printf("Code: %d\n", std_array[i].code);
            printf("Title: %s\n", std_array[i].title);
            printf("Year: %d\n", std_array[i].year);
            break;
        } else if (i==m_counter) {
            printf("Cannot find the movie, please enter the correct number next time!!");
            break;
        }
        
    }
}
