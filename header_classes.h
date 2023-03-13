/* Program name: classes.h
*  Author: Peter Durfey
*  Date last updated: 10/1/2022
* Purpose: classes for meal_plan
*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//class for user
class user
{

protected:
    string name, goal;
    double height, weight, bmi, gender, BMR, bodyfat;
    int age, max_hr;

public:
    user(string name, double height, double weight, int age, string gender, string goal, int bodyfat)
    {
        set_name(name);
        set_height(height);
        set_weight(weight);
        set_age(age);
        set_gender(gender);
        set_goal(goal);
        set_bmi();
        set_bodyfat(bodyfat);
        set_BMR();
        set_hr_range();
    }
    void set_hr_range()
    {
        this-> max_hr = 220 - this->age;
    }
    void set_bodyfat(int bodyfat)
    {
        if (this->gender == 1)
            switch (bodyfat)
            {  
                case 0 ... 14:
                    this->bodyfat = 1;
                    break;
                case 15 ... 20:
                    this->bodyfat = .95;
                    break;
                case 21 ... 28:
                    this->bodyfat = .9;
                    break;
                case 29 ... 100:
                    this->bodyfat = .85;  
            }
        else
        {
            switch (bodyfat)
            {
                case 0 ... 18:
                    this->bodyfat = 1;
                    break;
                case 19 ... 28:
                    this->bodyfat = .95;
                    break;
                case 29 ... 38:
                    this->bodyfat = .9;
                    break;
                case 39 ... 100:
                    this->bodyfat = .85;  
                    break;
            }
        }
    }
    void set_BMR()
    {
        if (this->goal == "maintain")
        {
            this->BMR = (weight * gender * 24 * bodyfat);
        }
        else if (this->goal == "gain weight")
        {
            this->BMR = (weight * gender * 24 * bodyfat) + 500;
        }
        else
        {
            this->BMR = (weight * gender * 24 * bodyfat) - 500;
        }
    }
    void set_bmi()
    {
        this->bmi = this->weight / pow(this->height, 2);
    }
    void set_goal(string goal)
    {
        this->goal = goal;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_height(double height)
    {
        this->height = height;
    }
    void set_weight(double weight)
    {
        this->weight = weight;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_gender(string gender)
    {
        if (gender == "male")
        {
            this->gender = 1;
        }
        else if (gender == "female")
        {
            this->gender = .9;
        }
    }
    string get_name()
    {
        return this->name;
    }
    string get_goal()
    {
        return this->goal;
    }
    double get_height()
    {
        return this->height;
    }
    double get_weight()
    {
        return this->weight;
    }
    int get_age()
    {
        return this->age;
    }
    double get_gender()
    {
        return this->gender;
    }
    double get_bmi()
    {
        return this->bmi;
    }
    double set_bodyfat()
    {
        return this->bodyfat;
    }
    double get_BMR()
    {
        return this->BMR;
    }

};

class workout_plan : public user
{
    private:
        string workout_split, cardio, goal;
    public:
        workout_plan(const user& move_user, int cardio, int workout_split, int goal) : user(move_user)
        {
            set_split(workout_split);
            set_cardio(cardio);
            set_goal(goal);
        }
        void set_split (int workout_split)
        {
            if (workout_split == 3)
            {
                this->workout_split = "Monday - cardio and chest/triceps/shoulders, Wednesday - cardio and legs, Friday - cardio and back/biceps/traps";
            }
            else if (workout_split == 4)
            {
                this->workout_split = "Monday - cardio and chest/triceps, Wednesday - cardio and legs, Friday - cardio and back/biceps, Saturday - shoulders/traps";
            }
            else if (workout_split == 5)
            {
                this->workout_split = "Monday cardio and chest, Tuesday - legs, Wednesday - cardio and back, Friday - arms/shoulders, Saturday cardio and traps";
            }
        }
        void set_cardio(int cardio)
        {
            if (cardio == 1)
            {
                this->cardio = "running";
            }
            else if (cardio == 2)
            {
                this->cardio = "biking";
            }
            else if (cardio == 3)
            {
                this->cardio = "elliptical";
            }
            else
            {
                this->cardio = "rowing";
            }
        }
        void set_goal(int goal)
        { 
            if (goal == 1)
            {
                this->goal = "sets of 5 - 5 sets of 4 exercises";
            }
            else if (goal == 2)
            {
                this->goal = "set of 8-10 - 4 sets of 3 exercises";
            }
            else
            {
                this->goal = "60 minutes of cardio, sets of 8-12, 3 sets of 3 exercises";
            }
        }
        string get_split()
        {
            return this->workout_split;
        }
        string get_cardio()
        {
            return this->cardio;
        }
        string get_string_goal()
        {
            return this->goal;
        }
        friend ostream &operator<<( ostream &output, const workout_plan &wp);
};

ostream& operator<<( ostream &output, const workout_plan &wp) 
{ 
     output << "Workout split details: " << wp.workout_split << "\n" << "\n"
            << "Cardio details: " << wp.cardio << "\n"
            << "Max Heartrate: " << wp.max_hr << "\n" << "\n"
            << "Modifications to plan based on goal: " << wp.goal << "\n" << "\n";
    return output;       
};  


//class for mealplans
class meal_plan : public user
{
    private:
        string protein, carbs, fat;
        double protein_grams, carbs_grams, fat_grams;

    public:
        meal_plan(const user& move_user, int protein, int carbs, int fat) : user(move_user)
        {
            set_protein(protein);
            set_carbs(carbs);
            set_fat(fat);
            set_protein_grams(protein);
            set_carbs_grams(carbs);
            set_fat_grams(fat);
        }
        string get_protein()
        {
            return protein;
        }
        string get_carbs()
        {
            return carbs;
        }
        string get_fat()
        {
            return fat;
        }
        double get_protein_grams()
        {
            return protein_grams;
        }
        double get_carbs_grams()
        {
            return carbs_grams;
        }
        double get_fat_grams()
        {
            return fat_grams;
        }
        void set_protein_grams(int protein)
        {
            int calories_per_gram;
            if (protein == 1)
            {
                calories_per_gram = 2;
            }
            else 
            {
                calories_per_gram = 4;
            }
            this->protein_grams = (((this->BMR)*.2)/calories_per_gram);
        }

        void set_carbs_grams(int carbs)
        {
            int calories_per_gram;
            if (carbs == 3)
            {
                calories_per_gram = 4;
            }
            else 
            {
                calories_per_gram = 1;
            }
            this->carbs_grams = (((this->BMR)*.5)/calories_per_gram);
        }
        void set_fat_grams(int fat)
        {
            int calories_per_gram;
            if (fat == 1)
            {
                calories_per_gram = 2;
            }
            else if (fat == 6)
            {
                calories_per_gram = 6;
            }
            else
            {
                calories_per_gram = 60;
            }
            this->fat_grams = (((this->BMR)*.3)/calories_per_gram);
        }
        void set_protein(int protein)
        {
            if(protein == 1)
            {
                this->protein = "chicken";
            }
            if(protein  == 2)
            {
                this->protein = "steak";
            }
            if(protein  == 2)
            {
                this->protein = "fish";
            }           
        }
        void set_carbs(int carbs)
        {
            if(carbs == 1)
            {
                this->carbs = "rice";
            }
            if(carbs  == 2)
            {
                this->carbs = "pasta";
            }
            if(carbs  == 2)
            {
                this->carbs = "oats";
            }           
        }
        void set_fat(int fat)
        {
            if(fat == 1)
            {
                this->fat = "egg";
            }
            if(fat  == 2)
            {
                this->fat = "nut";
            }
            if(fat  == 2)
            {
                this->fat = "whole milk";
            }   
        }
        friend ostream &operator<<( ostream &output, const meal_plan &mp);
};

ostream& operator<<( ostream &output, const meal_plan &mp) 
{ 
     output << "Total calorie needed: " << mp.BMR << "\n" << "\n"
            << "Protein source: " << mp.protein << "\n"
            << "Amount needed (in grams): " << mp.protein_grams << "\n" << "\n"
            << "Carb source: " << mp.carbs << "\n"
            << "Amount needed (in grams): " << mp.carbs_grams << "\n" << "\n"
            << "Fat source: " << mp.fat << "\n"
            << "Amount needed (in grams): " << mp.fat_grams << "\n" << "\n";     
    return output;       
};       


