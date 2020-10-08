#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>
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

    if (prompt)
    {
        cerr << "Enter number count: ";
        in >> data.number_count;

        cerr << "Enter numbers: ";
        data.numbers = input_numbers(in, data.number_count);

        cerr << "Enter column count: ";
        in >> data.bin_count;
    }
    else
    {
        in >> data.number_count;
        data.numbers = input_numbers(in, data.number_count);
        in >> data.bin_count;
    }


    return data;
}






nt main(int argc, char* argv[]) {

    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            cout << "argv[" << i << "] = " << argv[i] << endl;
        }
        return 0;
    }

    curl_global_init(CURL_GLOBAL_ALL);

    const auto input = read_input (cin, true);

    const auto bins = make_histogram(input);

    show_histogram_svg(bins, input.number_count);

    return 0;
}
