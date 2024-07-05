# Pagination Application
This application reads a text from `document.txt` and paginetes it. Each line in the paginated document contains a maximum of 80 characters, and each page contains 25 lines. A separation mark indicating the page number is added at the end of each page. The result is saved in `output_document.txt`.

## Requierements
- C++ compiler (GCC, Clang, MSVC, etc.)

## How to Run
1. Clone the repository.
2. Place your text content in the `document.txt` file.
3. Compile and run the application:

    ```sh
    g++ -o paginate main.cpp
    ./paginate
    ```
4. The output will be written to `output_document.txt` in the same directory.