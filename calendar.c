/* ====================================================================================================================
This project aims to create a calendar program in C that will display the days, months, and years. 
You can add some advanced features to the project that allows you to set reminders and schedule meetings. 
==================================================================================================================== */ 
#include <stdio.h>

void printLayout(){

}

int main(){
    const char *monthNames[12] = {"January", "February", "March", "April",
                                " May", "June", "July", "August",
                                "September", "October", "November", "December"};
    const char *daysOfTheWeek[7] = {"Monday", "Tuesday", "Wednesday",
                                    "Thursday", "Friday", "Saturday", "Sunday"};
    int monthNumberDaysEven[30] = {0};
    int monthNumberDaysOdd[31] = {0};
    int years[30] = {0};

    // Append numbers 1 to 30 to monthNumberDaysEven
    for (int i = 0; i < sizeof(monthNumberDaysEven)/sizeof(monthNumberDaysEven[0]); i++){
        monthNumberDaysEven[i] = i+1;
    }

    // Append numbers 1 to 31 to monthNumberDaysOdd
    for (int i = 0; i < sizeof(monthNumberDaysOdd)/sizeof(monthNumberDaysOdd[0]); i++){
        monthNumberDaysOdd[i] = i+1;
    }

    // Append numbers 2000 to 2030 to years
    for (int i = 0; i < sizeof(years)/sizeof(years[0]); i++){
        years[i] = i+2000;
    };

    // Loop through the months
    for (int i = 0; i < sizeof(monthNumberDaysEven)/sizeof(monthNumberDaysEven[0]); i++{
        printf("%s\n", *monthNames[i]);
    }
    



}
