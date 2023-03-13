#include "header_functions.h"

int main()
{
    //get input from user
   int x = 1;
   do
    {
        cout << "-------------------------------------------------------" << endl;;
        user temp_user = get_input();
        vector_of_users.push_back(temp_user);
        cout << "-------------------------------------------------------" << endl;
        cout << "Press 0 to enter another user or another number to exit user input: ";
        while (!(cin >> x))
        {
            validate();
        }
        cin.ignore();
    } while (x == 0);
    cout << "-------------------------------------------------------" << endl;
    
    x = 1;
    //creat loop for finding person to create plan for
    do
    {
    //ask for user to construct mealplan and workout program find out if user is in vector
    user* temp_user_class = loop_for_finding_user();

    //give reconmendation according to  bmi 18.5 to 24.9 and change goal according to result
    give_reconmendation_using_bmi(temp_user_class);

    //ask for protein source using menu
    int protein, carb, fat;
    protein =  protein_menu();
    carb = carb_menu();
    fat = fat_menu();
    //add meal plan to class
    meal_plan meal_user = meal_plan(*temp_user_class, protein, carb, fat);
    //output mealplan to txt file
    ofstream txt_file_name("txt.txt", std::ios::in | std::ios::out | std::ios::ate);
    if (txt_file_name.is_open())
    {
        txt_file_name << "Meal plan information for " << temp_user_class->get_name() << "\n";
        txt_file_name.close();
    }
    else cout << "Problem with opening file";
    write_plan_to_file<meal_plan*>(&meal_user);

    //ask for type of cardio and workout that is preferred
    int cardio, workout_split, goal;
    cardio = cardio_menu();
    workout_split = workout_split_menu();
    goal = goal_menu();
    //add to class
    workout_plan workout_user = workout_plan(*temp_user_class, cardio, workout_split, goal);
    //output to txt file
    ofstream txt_file1("txt.txt", std::ios::in | std::ios::out | std::ios::ate);
    if (txt_file1.is_open())
    {
        txt_file1 << "Workout plan information for " << temp_user_class->get_name() << "\n";
        txt_file1.close();
    }
    else cout << "Problem with opening file";
    write_plan_to_file<workout_plan*>(&workout_user);
            
    cout << "-------------------------------------------------------" << endl; 
    cout << "Press 0 to find and create a plan for another user or enter a different number to exit: ";
    while (!(cin >> x))
    {
        validate();
    }
    cin.ignore();
    } while (x == 0);
}

