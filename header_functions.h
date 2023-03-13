/* Program name: heaer.h
*  Author: Peter Durfey
*  Date last updated: 10/1/2022
* Purpose: header file for meal_plan
*/
#include "header_classes.h"
#include <vector>

//map for users
vector<user> vector_of_users;

//validate function single inputs
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    cout << "Re-Enter: ";
};
//function for getting input from user
user get_input()
{
    //variables that need to be retrieved from user
    string name, gender, goal;
    double height, weight;
    int age, bodyfat;
    //get input from user
    cout << "Enter name: ";
    while(!(getline(cin, name)) || (name.empty()))
    {
        validate();
    }
    cout << "Enter gender (male, female): ";
    while(!(cin >> gender))
    {
        validate();

    }
    //check for correct input of gender
    int re_input = 1;
    do
    {
        if(gender == "male" || gender == "female")
        {
            re_input = 0;
        }
        else 
        {
            validate();
            cin >> gender;
        }
    }while (re_input == 1);

    //get height
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter height in meters: ";
    while(!(cin >> height) || height < .5 || height > 3)
    {
        validate();
    }
    //get bodyfat percentage
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter bodyfat percentage: ";
    while(!(cin >> bodyfat))
    {
        validate();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //get weight
    cout << "Enter weight in kilograms: ";
    while(!(cin >> weight) || weight < 30 || weight > 453)
    {
        validate();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //get age
    cout << "Enter age: ";
    while(!(cin >> age))
    {
        validate();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //get goal
    cout << "Enter goal (gain weight, lose weight, or maintain current weight): ";
    getline(cin, goal);
    re_input = 1;
    //check if input is lose weight or gain weight or maintain
    do
    {
        if(goal == "gain weight" || goal == "lose weight" || goal == "maintain")
        {
        re_input = 0;
        }
        else 
        {
            cout << "Invalid input\n";
            cin.clear();
            cout << "Re-Enter: ";
            getline(cin, goal);
        }
    }while (re_input == 1);
    //create user with information
    user temp_user = user(name, height, weight, age, gender, goal, bodyfat);

    return temp_user;
};

//function for calculating max 
double calc_gain(double h, double w)
{
    double max_weight = (24.9) * (pow(h, 2));
    return round(max_weight - w);
};
//function for calculating min 
double calc_lose(double h, double w)
{
    double min_weight = (18.5) * (pow(h, 2));
    return round(w - min_weight);
};

//give reconmendation according to bmi 18.5 to 24.9
void give_reconmendation_using_bmi(user *user_var)
{
    cout << "The recommended bmi is between 18.5 and 24.9" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "The bmi of " << user_var->get_name() << " is " << user_var->get_bmi() << endl;
    if (user_var->get_goal() == "gain weight")
    {
        if(user_var->get_bmi() > 24.9)
        {
            cout << user_var->get_name() << "'s " << "BMI is greater than 24.9 and their goal of 'gain weight' is not recommended" << endl;
            double lose = 0 - (calc_gain(user_var->get_height(), user_var->get_weight()));
            cout << "They should lose at least " << lose << " kilograms" << endl;
            user_var->set_goal("lose weight");
        }
        else
        {
            cout << user_var->get_name() << "'s " << "Goal is in line with their current bmi" << endl;
            cout << "They can gain " << calc_gain(user_var->get_height(), user_var->get_weight()) << " kilograms and still be healthy" << endl;
        }
    }
    else if (user_var->get_goal() == "lose weight")
    {
        if(user_var->get_bmi() < 18.5)
        {
            cout << user_var->get_name() << "'s " << "BMI is less than 18.5 and their goal of 'lose weight' is not recommended" << endl;
            double gain = 0 - (calc_lose(user_var->get_height(), user_var->get_weight()));
            cout << "They should gain at least " << gain << " kilograms" << endl;
            user_var->set_goal("gain weight");
        }
        else
        {
            cout <<user_var->get_name() << "'s " << "Goal is in line with their current bmi" << endl;
            cout << "They can lose " << calc_lose(user_var->get_height(), user_var->get_weight()) << " kilograms and still be healthy" << endl;

        }
    }
    else 
    {
        if (user_var->get_bmi() < 18.5)
        {
            cout << "Although user wants to maintain weight, it is recomended they gain weight as their BMI is too low" << endl;
            double gain = 0 - (calc_lose(user_var->get_height(), user_var->get_weight()));
            cout << "They should gain at least " << gain << " kilograms" << endl;
            user_var->set_goal("gain weight");
        }
        else if (user_var->get_bmi() > 24.9)
        {
            cout << "Although user wants to maintain weight, it is recomended they lose weight as their BMI is too high" << endl;
            double lose = 0 - (calc_gain(user_var->get_height(), user_var->get_weight()));
            cout << "They should lose at least " << lose << " kilograms" << endl;
            user_var->set_goal("lose weight");
        }
        else
        {
            cout << "Users goal of maintaining weight is a healthy choice and inline with their bmi." << endl;
        }
    }
    cout << "-------------------------------------------------------" << endl;
};
//protein menu
int protein_menu()
{
    int protein; 

    cout << "Enter Protein Source" << endl;
    cout << "Enter 1 for chicken" << endl;
    cout << "Enter 2 for steak" << endl;
    cout << "Enter 3 for fish" << endl;

    while((!(cin >> protein)) || (protein <= 0) || (protein > 3))
    {
        validate();
    }
    return protein;
};
//fat menu
int fat_menu()
{
    int fat; 

    cout << "Enter Carbohydrate Source" << endl;
    cout << "Enter 1 for eggs" << endl;
    cout << "Enter 2 for nuts" << endl;
    cout << "Enter 3 for whole milk" << endl;

    while((!(cin >> fat)) || (fat <= 0) || (fat > 3))
    {
        validate();
    }
    return fat;
};
//carb menu
int carb_menu()
{
    int carb; 

    cout << "Enter carbohydrate Source" << endl;
    cout << "Enter 1 for rice" << endl;
    cout << "Enter 2 for pasta" << endl;
    cout << "Enter 3 for oats" << endl;

    while((!(cin >> carb)) || (carb <= 0) || (carb > 3))
    {
        validate();
    }
    return carb;
};

//protein menu
int cardio_menu()
{
    int cardio; 

    cout << "Enter preferred type of cardio: " << endl;
    cout << "Enter 1 for running" << endl;
    cout << "Enter 2 for biking" << endl;
    cout << "Enter 3 for elliptical" << endl;
    cout << "Enter 4 for rowing" << endl;

    while((!(cin >> cardio)) || (cardio <= 0) || (cardio > 4))
    {
        validate();
    }
    return cardio;
};

int workout_split_menu()
{
    int split; 

    cout << "Enter your preferred workout split: " << endl;
    cout << "Enter 3 for 3 days a week" << endl;
    cout << "Enter 4 for 4 days a week" << endl;
    cout << "Enter 5 for 5 days a week" << endl;

    while((!(cin >> split)) || (split < 3) || (split > 5))
    {
        validate();
    }
    return split;
};

int goal_menu()
{
    int goal; 

    cout << "Enter what your goal is with working out: " << endl;
    cout << "Enter 1 for gaining strength" << endl;
    cout << "Enter 2 for general health" << endl;
    cout << "Enter 3 for increasing endurance" << endl;

    while((!(cin >> goal)) || (goal <= 0) || (goal > 3))
    {
        validate();
    }
    return goal;
};

//add to txt file
template <typename T>
void write_plan_to_file(T pointer)
{
    ofstream txt_file("txt.txt", std::ios::in | std::ios::out | std::ios::ate);
    //check if file was successfully opened for writing
    if (txt_file.is_open())
    {
        txt_file << *pointer << "\n";
        txt_file.close();
    }
    else cout << "Problem with opening file";
};

//loop getting person info for creating mealplan
user* loop_for_finding_user()
{
    user * temp_user_class;
    string temp_user;
    int found = 1;
    do 
    {
        cout << "Enter user name to get info on: ";
        while(!(getline(cin, temp_user)))
        {
            validate();
        }
        //search vector for name
        cout << endl;
        int y = 0;
        for(auto & elem : vector_of_users)
        {
            if (vector_of_users[y].get_name() ==  temp_user)
            {
                found = 0;
                temp_user_class = &vector_of_users[y];
            }
            y++;
        }
        if (found == 1)
        {
            cout << "User not found" << endl;
        }
    } while (found == 1);
    return temp_user_class;
};