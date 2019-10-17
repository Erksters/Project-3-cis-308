#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Method to sort a list from smallest to greatest.
/// \param list = A list of numbers
/// \param n
void SortList(int list[], int n){
    int a;
    for (int i = 0; i < n; ++i)
    {

        for (int j = i + 1; j < n; ++j)
        {

            if (list[i] > list[j])
            {

                a =  list[i];
                list[i] = list[j];
                list[j] = a;
            }
        }
    }
}

void SortSize(int *number[], int n){
    int * a;
    for (int i = 0; i < n; ++i)
    {

        for (int j = i + 1; j < n; ++j)
        {
            int * first = number[i];
            int * second = number[j];
            if (sizeof(first)/ first[0] > sizeof(second)/ sizeof(second[0]))
            {

                a =  number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}

void printList(int number[]){
    int n = sizeof(number)/number[0];
    for(int i = 0; i < n; i++){
        printf("%d ", number[i]);
    }
}


int main() {
    FILE *fp;
    char strList[256];
    char firstNum[10];

    char* filename = "test.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    else{
        fgets(firstNum, sizeof(firstNum), fp);
        printf("There are %c lists to organize\n", firstNum[0]);

//        Looping through the N lists below
        char * token;
        int * allLists[atoi(firstNum)];
        int count = 0;
        for(int i =0 ; i<atoi(firstNum); i++){
            fgets(strList, sizeof(strList), fp);

            token = strtok(strList, ":");
            int length = atoi(token);
            int numbers[length];

            //Storing numbers in 'numbers'
            printf("From Text: ");

            for(int j = 0; j < length;j++){
                token = strtok(NULL, ",");
                numbers[j] = atoi(token);
                printf("%d ", numbers[j]);
            }
            printf("\n");
            //Sorting list here         //WORKS
            SortList(numbers, length);
            printf("Sorted List: ");
            for(int j = 0; j < length;j++){
                printf("%d ", numbers[j]);
            }
            printf("\n");

            //*************************************STUCK ON SAVING
//            printf("Saving list here\n");
            allLists[count] = numbers;
            count++;
        }
//        printf("\n");
//        printf("Finished Going through all the lists\n");
//        //Sorting through allLists here.
//        SortSize(allLists,atoi(firstNum));
//
//        printf("Printing to console here\n");
//        for(int x = 0; x < atoi(firstNum); x++){
//            int * sample = allLists[x];
//            printList(sample);
//        }
    }
    fclose(fp);
    return 0;
}












//    while (fgets(str, sizeof(str), fp) != NULL){
//        printf("%s", str);

//    }
