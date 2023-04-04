/*
Test_Score_Average.c

Violeta Solorio
March 23,2023

The program calculates the average score across all tests & of each student of struct type student.
*/
#include <stdio.h>
#define number_5 5
#define number_4 4
struct student//Creating data structure for student with attributes ID, Year of college and test scores
{
    long int id;
    int year_of_college;
    double test_scores[4];
};
double calculate_average(double number_array[]){//Helper function, calculates the average test score given a double array
    double average = 0;
    for(int i=0; i < 4 ; i++){
        average += number_array[i];
    }
    average = average / 4;
    return average;
};
void show_student_average(struct student scholar){	//Prints student ID and the average test score of that specific student
    printf("%ld    %.2f\n", scholar.id, calculate_average(scholar.test_scores));
};
void average_exam_score(struct student list[]){//Calculates average score between all students for each test given a struct of students
    printf("\nTest   Average Score\n");
    for(int i=0; i <number_4;i++ ){	//Will iterate through each of the four tests
        double summation_test = 0;	//Resets the average score
        for( int j=0; j < number_5;j++){	//Will calculate the test at i of student j and add the test to the summation
            summation_test += list[j].test_scores[i];
        }
        double total = summation_test / number_5;
        printf("%d      %.2f\n",i+1,total);//Prints average
    }
};
int main()
{
    struct student scholars[] = //Creates array of structs of type student
    {
        {9781473, 1, {97.25,96.5,90,87.5}},
        {6014552, 2 , {77.8, 80.0, 81.5, 79.5}},
        {3773909, 2 , {85.5, 79, 79, 90.5}},
        {8102274,1, {88.9, 90.5, 92, 94}},
        {4582934,1,{90, 90, 92, 89.5}}
    };
    printf("ID         Average Test Score\n");
    for(int i =0 ; i < number_5; i++){
        show_student_average(scholars[i]);
    }
    average_exam_score(scholars);
    return 0;
}
