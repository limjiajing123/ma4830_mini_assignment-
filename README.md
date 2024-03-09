The code is for the Mini CA for MA4830 Real-time Software for Mechatronics Systems

# Introduction:

The body mass index (BMI) is a value derived from the mass(kg) and height(m) of an individual. 

The BMI is defined as the body mass divided by the square of the body height and is expressed in units of kg/m2. 

𝐵𝑀𝐼 (𝑘𝑔/𝑚2) = 𝑀𝑎𝑠𝑠(𝑘𝑔) / 𝐻𝑒𝑖𝑔ℎ𝑡^2 (𝑚^2)

The BMI attempts to quantify the amount of tissue mass, muscle, fat, and bone, in an individual, and then categorise that person as underweight, normal weight, overweight, or obese based on that value.
BMI is a measurement of a person's leanness based on their height and weight, and is intended to quantify tissue mass. It is widely used as a general indicator of whether a person has a healthy body weight for their height. 
These ranges of BMI vary based on factors such as ethnicity.

The recommended BMI values are: 

• Asians: Low (<18.5), Normal (18.5 – 23.0), Overweight (23.0 – 27.5) Obese (>27.5)

• Non-Asian: Low (<18.5), Normal (18.5 – 24.9), Overweight (24.9 – 29.9) Obese (>29.9)

There are different classifications for Asians and non-Asians. With Asians the ideal BMI is lower than non-Asians.


# Details of the project:

**Produce a C Language Program to**:

- Compute the users BMI and to provide a preliminary assessment of the person’s health risk.

- Analyse and classify the user’s ideal BMI (Low, Normal, Overweight, Obese)

- Recommended “mass” reduction required to take the user’s assessment to a “normal” state.

**Your program should accept the necessary input parameters and compute the necessary indicators.**

- Accept inputs using function the C language scanf() function and/or as        command line arguments.
- Check for invalid data and provide user assistance
- Exclude excessive weight, height and other non valid inputs.
- Compute BMI value and provide weight change recommendations
- Arrange your output into a readable table showing data entered by the user, BMI value and lifestyle recommendations

**Real-time check of data input**
- Check range of input values for improbable inputs and any additional data required (if required)
- Assume adult users with plausible weight and height ranges.
- Help & suggestion in identification of input error.
- Software robustness
- Stable operation and avoidance of infinite loop or programming “hanging”
- Pleasant format of output results

# **Instructions to Run the code**:
1. **Windows**:

    - Download the MinGW zip file from this [Google Drive link](https://drive.google.com/file/d/1J10JDUijGxiJ25wiSlyEG0QiLmiE2Xsr/view?usp=drive_link).
    - Unzip the file.
    - Move the unzipped folder to the C:\ drive (resulting in a path like C:\mingw).
    - Navigate to the bin folder inside the MinGW folder.
    - Copy the path to this bin folder.

2. **Add MinGW to System Path**:

    - Type "Edit environment variables for your account" in the Windows search bar and select it.
    - Click on "Environment Variables..."
    - Under "User variables", find the "Path" variable and click "Edit".
    - Add a new entry with the copied path to the MinGW bin folder.
    - Click "OK" to close the dialogs.


Run code with GCC compiler

In VS code, open terminal and run command  

**command to run**

```bash
gcc mini_ca.c -o mini_ca
```


