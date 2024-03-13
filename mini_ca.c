#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to calculate BMI according to the formula
float calculate_BMI(float weight, float height) {
    return weight / (height * height);
}

// Function to classify BMI
void classify_BMI(float bmi, int is_asian) {
    
    if (is_asian) 
        {printf("|%*sAsian%*s|\n", 20, "", 20, "");} 
    else 
        {printf("|%*sNon-Asian%*s|\n", 18, "", 18, "");}

    printf("|---------------------------------------------|\n");
    printf("| %*s BMI (kg/m^2)%*s | %*sHealth Risk %*s |\n", 4, "", 3, "", 4, "", 4, "");
    printf("|----------------------|----------------------|\n"); 
    
    char str[20];
    
    if (is_asian) //classify asian BMI low, normal, overweight or obese
    {
        if (bmi < 18.5)
            {strcpy(str, "   Low    ");}
        else if (bmi >= 18.5 && bmi <= 23.0)
            {strcpy(str, "  Normal  ");}
        else if (bmi > 23.0 && bmi <= 27.5)
            {strcpy(str, "Overweight");}
        else
            {strcpy(str, "  Obese   ");}
    } else //classify non-asian BMI low, normal, overweight or obese
    {
        if (bmi < 18.5)
            {strcpy(str, "   Low    ");}
        else if (bmi >= 18.5 && bmi <= 24.9)
            {strcpy(str, "  Normal  ");}
        else if (bmi > 24.9 && bmi <= 29.9)
            {strcpy(str, "Overweight");}
        else
            {strcpy(str, "  Obese   ");}
    }
    printf(" %*s %.2f%*s %*s%s%*s \n", 8, "", bmi, 8, "", 6, "", str, 6, ""); //print BMI and their BMI status
}

// Function to provide recommendations
void body_weight_advice(float bmi, float height, int is_asian) {
    
    printf( "|---------------------------------------------|\n"
            "|          Weight Change Recommendation       |\n"
            "|---------------------------------------------|\n");
    
    //declaring variables
    float idealBMI;  
    float lower_normal_BMI;
    float upper_normal_BMI;

    //setting bmi value based on is_asian and non-asian bmi values 
    if (is_asian) {
        lower_normal_BMI = 18.5;
        upper_normal_BMI = 23.0;
        idealBMI = 21.75;           // Average of normal range for Asians
    } else {
        lower_normal_BMI = 18.5;
        upper_normal_BMI = 24.9;
        idealBMI = 21.7;            // Average of normal range for Non-Asians
    }

    float idealWeight = idealBMI * (height * height);
    float lower_bound = abs(bmi - lower_normal_BMI) * (height * height);
    float upper_bound = abs(bmi - upper_normal_BMI) * (height * height);

    printf("| Normal range for BMI : %.2f kg to %.2f kg |\n", lower_normal_BMI, upper_normal_BMI);
    printf("|---------------------------------------------|\n");

    if (bmi > upper_normal_BMI) //if BMI is above normal range, exercise advice is given
    {
        printf("| You should consider reducing your weight by |\n");
        printf("%*s%.2f kg to %.2f kg %*s\n", 12, "",upper_bound, lower_bound, 12, "");
        printf("|%*sto reach within a normal BMI Range.%*s|\n", 5, "", 5, "");
        printf( "|---------------------------------------------|\n"
                "|          Weight Loss Recommendations        |\n"
                "|1.Develop a reasonable diet plan             |\n"
                "|2.Engage in appropriate exercises            |\n"
                "|3.Control meal timing                        |\n"
                "|4.Pay attention to eating habits             |\n"
                "|5.Monitor weight changes and adjust the plan |\n"
                "|---------------------------------------------|\n\n");

    } 
    if (bmi < lower_normal_BMI) //if BMI is below normal range, lifestyle advice is given
    { 
        printf("|You should consider increasing your weight by|\n");
        printf("%*s%.2f kg to %.2f kg %*s\n", 12, "",lower_bound, upper_bound, 12, "");
        printf("|%*sto reach within a normal BMI Range.%*s|\n", 5, "", 5, "");
        printf( "|---------------------------------------------|\n"
                "|          Weight Gain Recommendations        |\n"
                "|1.Maintain a balanced diet                   |\n"
                "|2.Eat more frequently                        |\n"
                "|3.Choose foods with high energy density      |\n"
                "|4.Increase muscle mass                       |\n"
                "|5.Avoid excessive exercise                   |\n"
                "|---------------------------------------------|\n\n");
    }
    if (bmi >= lower_normal_BMI && bmi <= upper_normal_BMI) //if BMI is within normal range, lifestyle advice is given
    {
        printf( 
                "|       You are within the normal range       |\n"
                "|            Keep up the good work!           |\n"
                "|---------------------------------------------|\n\n");
    }
}

// Function to check if input is valid
bool is_valid(const char *str) { 
    
    if (str == NULL || *str == '\0') { //check if input is null or empty
        return false;
    }

    while (*str != '\0') {
        if (!isdigit(*str)) {return false;} //check if input is a number
        str++; 
    }

    return true;
}

// Function to reprompt user input if invalid
float get_user_input(const char *message, float min, float max, bool BMI_ref_source) {
    
    float value;
    bool isValidInput = false;
    char input[100];

    do {
        printf("%s", message);        //printing message to user from main function
        scanf("%s", input);          //taking input from user in terms of string
        
        if (!is_valid(input)) 
        {printf("Invalid input. Please enter a number.\n");} 
        
        else {
            if (BMI_ref_source){
                value = atoi(input);   //atoi function converts string to integer
                if (value != 0 && value != 1)  //if value is not 0 or 1
                {printf("Invalid input. Please enter a value exactly %d or %d.\n", 0, 1);}  //ask user to enter 0 or 1
                else
                {isValidInput = true;} //input is valid
            }
            else{
                value = atof(input); //atof function converts string to float
                if (value <= min || value > max) 
                {printf("Invalid input. Please enter a value between %.2f and %.2f.\n", min, max);} //ask user to enter value between min and max
                else
                {isValidInput = true;}//input is valid
            }
        }

    } while (!isValidInput); //if input is not valid, reprompt

    return value;
}

// Main function
int main() {

    // Accept inputs
    //calling the function of get_user_input, printing message, weight limit,  BMI_ref_source to choose Asian or Non-Asian
    float weight = get_user_input("Enter your weight in kg: ", 0, 300, false);  
    float height = get_user_input("Enter your height in cm: ", 0, 300, false) / 100;      
    int is_asian = get_user_input("Are you Asian? [Yes: 1, No: 0]: ", 0, 300, true);     

    // calling function to Calculate BMI
    float bmi = calculate_BMI(weight, height);

    // Output results in a table
    printf( "\n|---------------------------------------------|\n"
              "|            Body Mass Index Report           |\n"
              "|The body mass index (BMI) is a value derived |\n"
              "|from the mass and height of an individual.   |\n"
              "|It is widely used as a general indicator of  |\n"
              "|whether a person has a healthy body weight.  |\n"
              "|---------------------------------------------|\n");
    
    printf("| %*sWeight Entered (kg)%*s | %*sHeight Entered (m)%*s |\n", 1, "", 0, "", 1, "", 1, "");
    printf("|----------------------|----------------------|\n");
    printf(" %*s%.2f%*s %*s%.2f%*s\n", 8, "", weight, 10, "", 8, "", height, 8, "");
    printf("|---------------------------------------------|\n");
    
    classify_BMI(bmi, is_asian); //calling function to classify BMI
    body_weight_advice(bmi, height, is_asian); //calling function to give advice based on BMI

    return 0;
}
