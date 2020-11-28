#include <iostream>
#include <sstream>

const std::string generate_number(const std::string& seed)
{
    std::ostringstream output;

    for(size_t i=0; i != seed.length();)
    {   
        std::size_t found_index = seed.find_first_not_of(seed.at(i), i+1); //starting from position i+1 within the seed string
                                                                     // first the first character that is not the same as seed.at(i)
        if(found_index == std::string::npos)  // if a different character was never found_index , we have traversed the entire string
        {
            found_index = seed.length();        // so set found_index equal to seed.length
        }

        output << found_index - i << seed.at(i); // we found found_index occurences of the character seed.at(i)

        i = found_index;    // for the next iteration we need to checkthe next character so start from i = found_index;
    }

    return output.str();
}

int main()
{
    std::string seed;   // the initial seed
    int number_of_reps;

    std::cout << "Give the starting seed : ";
    std::cin >> seed;

    std::cout << "How many numbers to compute ? : ";    
    std::cin >> number_of_reps;

    std::cout << "The first " << number_of_reps - 1 << " number of the Look-and-say sequence are :\n" << std::endl;

    std::cout << seed << std::endl; // the first number is always the given seed

    for(size_t i=0; i< number_of_reps-1; i++)
    {
        seed = generate_number(seed);
        std::cout << seed << std::endl;
    }

    return 0;
}

