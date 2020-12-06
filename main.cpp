// Author: Gavin R Lafferty
// Github: https://github.com/TheRealGavin/homework_08
// December 05, 2020
// CSIS 113A

#include <iostream>
#include <random>

// Define functions used below
int random_number_generator(int min, int max);
void fill_array(int array[][5], int size);
void print_array(int array[][5], int size);
int count_numbers(int array[][5], int size, int search);

int main() {

  // Create two-dimensional array of 5 row and 5 columns
  int array[5][5];

  const int kSize = 5;

  // Call fill_array and print_array functions and pass the array and it's number of rows (kSize)
  fill_array(array, kSize);
  print_array(array, kSize);

  // Prompt user for number to be passed through count_numbers function
  std::cout << "\nWhat number do you want to search for? " << std::endl;
  int search_number;
  std::cin >> search_number;

  // Create count integer and set it equal to the count_numbers function ->
  // While passing through it the array, it's size, and the user inputted number
  int count = count_numbers(array,kSize,search_number);
  // Output count integer and coordinates of user inputted number via count_numbers function
  std::cout << "Your number appears " << count
            << " times in the array" << std::endl;

}


// Create a function that is passed an array and an integer (the # of rows) ->
// that fills an array with random numbers through a nested for loop
void fill_array(int array[][5], int size){

  // Outer loop moves through the array's rows while the inner loop moves
  // through the columns and fills the array with random numbers
  // using random_number_generator function
  for(int row = 0; row < size; ++row){
    for(int column = 0; column < 5; ++column){
        array[row][column] = random_number_generator(1,10);
    }
  }
}


// Create a function that is passed an array and an integer (the # of rows) ->
// that outputs the array from the fill_array function through a nested for loop
void print_array(int array[][5], int size){

  // Similar to the fill_array function, this nested loop
  // moves through the array via a nested loop, outputting the numbers
  // in an entire row before moving to the next column
  for(int row = 0; row < size; ++row){
    for(int column = 0; column < 5; ++column){
      std::cout << array[row][column] << "\t";
    }
    std::cout << std::endl;
  }
}


// Create a function that is passed an array, an integer (# of rows),
// and a second integer (user search value)
int count_numbers(int array[][5], int size, int search){
  int count = 0;

  // Using a nested loop to move through the array,
  // the user requested value is searched for via
  // an if statement that counts the number and outputs it's coordinates
  // using the current value of the row and column variables
  for(int row = 0; row < size; ++row){
    for(int column = 0; column < 5; ++column){
      if(array[row][column] == search){
        ++count;
        std::cout << "Your number appears at: ("
                  << row + 1 << "," << column + 1 << ")\n";
      }
    }
  }
  return count;
}


// Create a function that is passed two integers (min and max)
// that utilizes the mt19937 engine to generate
// and return random numbers within a given range
int random_number_generator(int min, int max){

  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> distribution(min, max);

  return distribution(rng);
}