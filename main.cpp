#include <iostream>
#include <vector>
#include <string>
#include "histogram.h"
#include "svg.h"
using namespace std;

vector<double> input_numbers(istream& in, const size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        in >> result[i];
    }

    return result;
}



Input
read_input(istream& in, bool prompt) {
    Input data;
    size_t number_count;

    if (prompt)
    {
        cerr << "Enter number count: ";
        in >> number_count;

        cerr << "Enter numbers: ";
        data.numbers = input_numbers(in, number_count);
        cerr << "Enter column count: ";
        in >> data.bin_count;
    }
    else
    {
        in >> number_count;
        data.numbers = input_numbers(in, number_count);
        in >> data.bin_count;
    }
    return data
}






int main() {

    /*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin, number_count);*/
    const auto input = read_input (cin, true );


    /*size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;*/


    const auto bins = make_histogram(input);


    show_histogram_text(bins);

    return 0;
}
