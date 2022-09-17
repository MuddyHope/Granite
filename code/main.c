#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define PATH "todolist.txt"


void fileoptions(); 
void filecloser();
void InsertTodoTask();
void deleteTodoTask();


//global variables
FILE *fp;

struct Todo{
    int index;
    char task[100];
    struct Todo *next;
};

struct Todo *root;          //pointer to root




int main(){

    fileoptions();            //FILE OPENER FUNCTION
    return 0;
    filecloser();
}


void fileoptions(){

    //creating a file pointer (fp)
    fp = fopen(PATH, "ab+");
    if (fp == NULL){
        printf("Can't open");
    }
    
    int option;
    printf("What task you want to do?\n");
    printf("1) New task\n");
    printf("2) Delete task\n");
    printf("3) Show all tasks\n");
    printf("3) Exit\n");
    printf("\nChoice is:   ");
    scanf("%d", &option);

    switch(option){
        case 1: InsertTodoTask();
        break;
        case 2: deleteTodoTask();
        break;
        //case 3: showall();
        //break;
        default: filecloser();
        break;
    }  
}


void InsertTodoTask(){
    char query[100];
    printf("Enter the task you want to add?");
    fflush(stdin);                      //used to clear the output buffer of the stream
    //fgets(query,100,stdin);
    struct Todo *temp = malloc(sizeof(struct Todo));
    printf("\n%s", query);
    temp->index +=1;
    temp->task = fgets(query,100,stdin);
    temp->next = NULL;
}

void deleteTodoTask(){
    printf("delete");
}




void filecloser(){
    fclose(fp);
}