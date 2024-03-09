#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to calculate BMI
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
    
    if (is_asian) {
        if (bmi < 18.5)
            {strcpy(str, "   Low    ");}
        else if (bmi >= 18.5 && bmi <= 23.0)
            {strcpy(str, "  Normal  ");}
        else if (bmi > 23.0 && bmi <= 27.5)
            {strcpy(str, "Overweight");}
        else
            {strcpy(str, "  Obese   ");}
    } else {
        if (bmi < 18.5)
            {strcpy(str, "   Low    ");}
        else if (bmi >= 18.5 && bmi <= 24.9)
            {strcpy(str, "  Normal  ");}
        else if (bmi > 24.9 && bmi <= 29.9)
            {strcpy(str, "Overweight");}
        else
            {strcpy(str, "  Obese   ");}
    }
    printf(" %*s %.2f%*s %*s%s%*s \n", 8, "", bmi, 8, "", 6, "", str, 6, "");
}

// Function to provide recommendations
void body_weight_advice(float bmi, float height, int is_asian) {
    
    printf( "|---------------------------------------------|\n"
            "|          Weight Change Recommendation       |\n"
            "|---------------------------------------------|\n");
    
    float idealBMI;
    float lower_normal_BMI;
    float upper_normal_BMI;

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

    if (bmi > upper_normal_BMI) {
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
    if (bmi < lower_normal_BMI) {
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
    if (bmi >= lower_normal_BMI && bmi <= upper_normal_BMI)
    {
        printf( 
                "|       You are within the normal range       |\n"
                "|            Keep up the good work!           |\n"
                "|---------------------------------------------|\n\n");
    }
}

// Function to check if input is valid
bool is_valid(const char *str) {
    
    if (str == NULL || *str == '\0') {
        return false;
    }

    while (*str != '\0') {
        if (!isdigit(*str)) {return false;}
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
        printf("%s", message);
        scanf("%s", input);
        
        if (!is_valid(input)) 
        {printf("Invalid input. Please enter a number.\n");} 
        
        else {
            if (BMI_ref_source){
                value = atoi(input);
                if (value != 0 && value != 1) 
                {printf("Invalid input. Please enter a value exactly %d or %d.\n", 0, 1);} 
                else
                {isValidInput = true;}
            }
            else{
                value = atof(input);
                if (value <= min || value > max) 
                {printf("Invalid input. Please enter a value between %.2f and %.2f.\n", min, max);} 
                else
                {isValidInput = true;}
            }
        }

    } while (!isValidInput);

    return value;
}

// Main function
int main() {

    // Accept inputs
    float weight = get_user_input("Enter your weight in kg: ", 0, 300, false);
    float height = get_user_input("Enter your height in cm: ", 0, 300, false) / 100;
    int is_asian = get_user_input("Are you Asian? [Yes: 1, No: 0]: ", 0, 300, true);

    // Calculate BMI
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
    
    classify_BMI(bmi, is_asian);
    body_weight_advice(bmi, height, is_asian);

    return 0;
}
