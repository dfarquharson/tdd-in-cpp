// followed along and transcribed by hand from here:
// https://learnxinyminutes.com/docs/c++/

// I took some liberties and wrapped a lot of the examples in test cases so they can be more easily run
// and so I can feel better about their results

#include "catch.hpp"

// Couldn't name this `main` because that's already been taken by the synthetic `main` from dsjf-test-playground.cpp
// How do I have both a `main` in my sources and a `main` in my tests? Separate builds?
int learnCpp(int argc) {
    return 0;
}

TEST_CASE("Character size", "[char]") {
    REQUIRE(learnCpp(0) == 0);
    REQUIRE(sizeof('c') == sizeof(char));
    REQUIRE(sizeof(char) == 1);
    REQUIRE(sizeof(int) == 4);
}

// C++ has strict prototyping
void func(); // function which accepts no arguments

// In C
void func(); // function which may accept any number of arguments

// Use nullptr instead of NULL in C++
int *ip = nullptr;

// C standard headers are available in C++
// C headers end in .h, while
// C++ headers are prefixed with "c" and have no ".h" suffix

// The C++ standard version:
#include <cstdio>

// The C standard version:
//#include <stdio.h> // not necessary if we're already using cstdio

int hello() {
    printf("Hello, world!\n");
    return 0;
}

TEST_CASE("Hello", "[hello]") {
    REQUIRE(hello() == 0);
}

///////////////////////
// Function Overloading
///////////////////////

// C++ supports function overloading
// provided each function takes different parameters

void print(char const *myString) {
    printf("String %s\n", myString);
}

void print(int myInt) {
    printf("My int is %d", myInt);
}

int usePrint() {
    print("Hello");
    print(15);
    return 0;
}

TEST_CASE("Overloaded Functions", "[overloaded]") {
    REQUIRE(usePrint() == 0);
}

/////////////////////////////
// Default function arguments
/////////////////////////////

// You can provide default arguments for a function
// if they are not provided by the caller

int doSomethingWithInts(int a = 1, int b = 4) {
    return a + b;
}

TEST_CASE("Default arguments", "[default-args]") {
    REQUIRE(doSomethingWithInts() == 5);
    REQUIRE(doSomethingWithInts(2) == 6);
    REQUIRE(doSomethingWithInts(1, 1) == 2);
}

// Default arguments must be at the end of the arguments list
//void invalidDeclaration(int a = 1, int b) {} // doesn't compile because that's illegal

/////////////
// Namespaces
/////////////

// Namespaces provide separate scopes for variable, function, and other declarations
// Namespaces can be nested

namespace First {
    namespace Nested {
        void foo() {
            printf("This is First::Nested::foo\n");
        }
    }
}

namespace Second {
    void foo() {
        printf("This is Second::foo\n");
    }
}

void foo() {
    printf("This is global foo\n");
}

int namespaces() {
    // Includes all symbols from namespace Second into the current scope.
    // Note that simply foo() no longer works, since it is now ambiguous
    // whether we're calling the foo in namespace Second or the top level.
    using namespace Second;

    Second::foo();
    First::Nested::foo();
    ::foo();
    return 0;
}

TEST_CASE("Namespaces") {
    REQUIRE(namespaces() == 0);
}

///////////////
// Input/Output
///////////////

// C++ input and output uses streams
// cin, cout, and cerr represent stdin, stdout, and stderr
// << is the insertion operator and >> is the extraction operator

#include <iostream>

using namespace std; // Streams are in the std namespace (standard library)

int io() {
    int myInt;

    // Print to stdout (or terminal/screen)
    cout << "Enter your favorite number\n";
    // Takes in input
    // can't do this interactively in the test, so myInt is whatever it gets default initialized to, which is apparently 0;
//    cin >> myInt;

    // cout can also be formatted
    cout << "Your favorite number is " << myInt << "\n";

    cerr << "Used for error messages";

    return 0;
}

TEST_CASE("I/O") {
    REQUIRE(io() == 0);
}

//////////
// Strings
//////////

// Strings in C++ are objects and have many member functions
# include <string>

using namespace std; // Strings are also in the namespace std (Standard Library)

string myString = "Hello";
string myOtherString = " World";

// + is used for concatenation
int doStringThings() {
    cout << myString + myOtherString << endl;
    cout << myString + " You" << endl;
    // C++ strings are mutable
    myString.append(" Dog");
    cout << myString << endl;
    cout << myString + myOtherString << endl;
    return 0;
}

TEST_CASE("Strings") {
    REQUIRE(doStringThings() == 0);
}

/////////////
// References
/////////////

// In addition to pointers like the ones in C,
// C++ has _references_.
// These are pointer types that cannot be reassigned once set
// and cannot be null.
// They also have the same syntax as the variable itself:
// No * is needed for dereferencing and
// & (address of) is not used for assignment.

using namespace std;

string myFoo = "I am foo";
string myBar = "I am bar";

int doReferenceStuff() {
    string &fooRef = myFoo; // this creates a reference to myFoo
    fooRef += ". Hi!"; // Modifies myFoo through the reference
    cout << fooRef << endl;

    cout << &fooRef << endl; // prints the address of myFoo
    fooRef = myBar;
    cout << &fooRef << endl; // still prints the address of myFoo

    cout << fooRef; // prints "I am bar"

    const string &barRef = myBar;
    // barRef += ". Hi!"; // can't modify it because it's const

    return 0;
}

string tempObjectFun() {
    return "tempObjectFun";
}

string retVal = tempObjectFun();

TEST_CASE("References") {
    REQUIRE(doReferenceStuff() == 0);
    REQUIRE(retVal == "tempObjectFun");
}

///////////
// Enums //
///////////

// Enums are a way to assign a value to a constant most commonly used for
// easier visualization and reading of code
enum ECarTypes {
    Sedan,
    Hatchback,
    SUV,
    Wagon
};

ECarTypes getPreferredCarType() {
    return ECarTypes::Hatchback;
}

TEST_CASE("Enums") {
    REQUIRE(getPreferredCarType() == ECarTypes::Hatchback);
    REQUIRE(ECarTypes::Hatchback == 1);
}

/////////////////////
// Classes and OOP //
/////////////////////

// First example of classes
#include <iostream>

// Declare a class.
// Classes are usually declared in header (.h or .hpp) files.
class Dog {
    // Member variables and functions are private by default.
    std::string name;
    int weight;

// All members following this are public
// until "private:" or "protected:" is found.
public:

    // Default constructor
    Dog();

    // Member function declarations (implementations to follow)
    // Note that we use std::string here instead of placing
    // using namespace std;
    // above.
    // Never put a "using namespace" statement in a header.
    void setName(const std::string &dogsName);

    void setWeight(int dogsWeight);

    // Functions that do not modify the state of the object
    // should be marked as const
    // This allows you to call them if given a const reference to the object.
    // Also note the functions must be explicitly declared as _virtual_
    // in order to be overridden in derived classes.
    // Functions are not virtual by default for performance reasons.
    virtual void print() const;

    // Functions can also be defined inside the class body.
    // Functions defined as such are automatically inlined.
    void bark() const {
        std::cout << name << " barks!\n";
    }

    // Along with constructors, C++ provides destructors.
    // These are called when an object is deleted or falls out of scope.
    // This enables powerful paradigms such as RAII
    // (see below)
    // The destructor should be virtual if a class is to be derived from;
    // if it is not virtual, then the derived class' destructor will
    // not be called if the object is destroyed through a base-class reference
    // or pointer.
    virtual ~Dog();

}; // A semicolon must follow the class definition.

// Class member functions are usually implemented in .cpp files.
Dog::Dog() {
    std::cout << "A dog has been constructed!\n";
}

// Objects (such as strings) should be passed by reference
// if you are modifying them or const reference if you are not.
void Dog::setName(const std::string &dogsName) {
    name = dogsName;
}

void Dog::setWeight(int dogsWeight) {
    weight = dogsWeight;
}

// Notice that "virtual" is only needed in the declaration, not the definition.
void Dog::print() const {
    std::cout << "Dog is " << name << " and weighs " << weight << "kg\n";
}

Dog::~Dog() {
    std::cout << "Goodbye " << name << "\n";
}

TEST_CASE("Objects") {
    Dog myDog;
    myDog.setName("Barkley");
    myDog.setWeight(10);
    myDog.print();
}

// Inheritance:

// This class inherits everything public and protected from the Dog class
// as well as private but may not directly access private members/methods
// without a public or protected method for doing so
class OwnedDog : public Dog {

public:
    void setOwner(const std::string &dogsOwner);

    // Override the behavior of the print function for all OwnedDogs.
    // See http://en.wikipedia.org/wiki/Polymorphism_(computer_science)#Subtyping
    // for a more general introduction if you're unfamiliar with
    // subtype polymorphism.
    // The override keyword is optional but makes sure you are actually
    // overriding the method in a base case.
    void print() const override;

private:
    std::string owner;
};

// Meanwhile, in the corresponding .cpp file:

void OwnedDog::setOwner(const std::string &dogsOwner) {
    owner = dogsOwner;
}

void OwnedDog::print() const {
    Dog::print(); // Call the print function in the base Dog class
    std::cout << "Dog is owned by " << owner << "\n";
}

TEST_CASE("Inheritance") {
    OwnedDog myDog;
    myDog.setName("Barkley");
    myDog.setWeight(10);
    myDog.setOwner("Me");
    myDog.print();
}

/////////////////////////
// Map, Filter, Reduce //
/////////////////////////


TEST_CASE("Map") {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i * i; }); // mutates vec?!? BLEH!!!
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        std::cout << *i << ' ';
    }
    std::cout << endl;
    std::vector<int> expected{1, 4, 9, 16, 25, 36, 49, 64, 81};
    REQUIRE(vec == expected);
}

TEST_CASE("Filter") {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    REQUIRE(2 % 2 == 0);
    REQUIRE(1 % 2 != 0);

    std::vector<int> evens;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(evens), [](int i) { return i % 2 == 0; });
    for (auto &i : evens) { // magical "range-based" loop instead of old-style above
        std::cout << i << ' ';
    }
    std::cout << endl;
    std::vector<int> expectedEvens{2, 4, 6, 8};
    REQUIRE(evens == expectedEvens);

    std::vector<int> odds;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(odds), [](int i) { return i % 2 != 0; });
    for (auto &i : odds) {
        std::cout << i << ' ';
    }
    std::cout << endl;
    std::vector<int> expectedOdds{1, 3, 5, 7, 9};
    REQUIRE(odds == expectedOdds);
}

TEST_CASE("Reduce") {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<string> str{"Programming", "in", "a", "functional", "style."};

    REQUIRE(std::accumulate(vec.begin(), vec.end(), 0, [](int a, int b) { return a + b; }) == 45);
    REQUIRE(std::accumulate(vec.begin(), vec.end(), 1, [](int a, int b) { return a * b; }) == 362880);
    REQUIRE(std::accumulate(str.begin(), str.end(), string(""),
                            [](std::string a, std::string b) { return a + ":" + b; }
    ).compare("Programming:in:a:functional:style."));
}

//////////////////////////////////////////////
// Initialization and Operation Overloading //
//////////////////////////////////////////////

// In C++ you can overload the behavior of operators such as +, -, *, /, etc.
// This is done by defining a function which is called
// whenever the operator is used

#include <iostream>

using namespace std;

class Point {
public:
    // Member variables can be given default values in this manner.
    double x = 0;
    double y = 0;

    // Define a default constructor which does nothing
    // but initialize the Point to the default value (0, 0)
    Point(double a, double b) :
            x(a),
            y(b) { /* Do nothing except initialize the values */ };

    // Overload the + operator
    Point operator+(const Point &rhs) const;

    // Overload the += operator
    Point &operator+=(const Point &rhs);

    // Overload the - operator
    Point operator-(const Point &rhs) const;

    // Overload the -= operator
    Point &operator-=(const Point &rhs);

    // Overload the == operator
    bool operator==(const Point &rhs) const;
};

Point Point::operator+(const Point &rhs) const {
    // Create a new point that is the sum of this one and rhs.
    return {x + rhs.x, y + rhs.y}; // another way of saying `Point(x + rhs.x, y + rhs.y)`
}

Point Point::operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
}

// It's good practice to return a reference to the leftmost variable of
// an assignment. `(a += b) == c` will work this way.
Point &Point::operator+=(const Point &rhs) {
    x += rhs.x;
    y += rhs.y;

    // `this` is a pointer to the object, on which a method is called.
    return *this;
}

Point &Point::operator-=(const Point &rhs) {
    x -= rhs.x;
    y -= rhs.y;

    return *this;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

TEST_CASE("Operator Overloading") {
    Point up(0, 1);
    Point right(1, 0);
    // This calls the Point + operator
    Point result = up + right;
    Point expected(1, 1);
    REQUIRE(result == expected);
}

///////////////
// Templates //
///////////////

// Templates in C++ are mostly used for generic programming, though they are
// much more powerful than generic constructs in other languages.
// They also support explicit and partial specialization and functional-style type
// classes; in fact, they are a Turing-complete functional language embedded in C++!

// We start with the kind of generic programming you might be familiar with.
// To define a class or function that takes a type parameter:
template<class T>
class Box {
public:
    // In this class, T can be used as any other type.
    T insert(const T t);
};

template<class T>
T Box<T>::insert(const T t) {
    return t;
}

TEST_CASE("Templates") {
    // During compilation, the compiler actually generates copies of each template
    // with parameters substituted, so the full definition of the class must be
    // present at each invocation. This is why you will see template classes defined
    // entirely in header files.

    // To instantiate a template class on the stack:
    Box<int> intBox;

    // and you can use it as you would expect:
    REQUIRE(intBox.insert(123) == 123);

    // You can, of course, nest templates:
    Box<Box<int>> boxOfBox;
    boxOfBox.insert(intBox);

    // Until C++11, you had to place a space between the two '>'s, otherwise '>>'
    // would be parsed as the right shift operator

    // You will sometimes see
    //   template<typename T>
    // instead. The 'class' keyword and 'typename' keywords are _mostly_
    // interchangeable in this case. For the full explanation, see
    //   http://en.wikipedia.org/wiki/Typename
    // (yes, that keyword has its own Wikipedia page).
}

// Similarly, a template function:
template<class T>
void barkThreeTimes(const T &input) {
    input.bark();
    input.bark();
    input.bark();
}

// Notice that nothing is specified about the type parameters here.
// The compiler will generate and then type-check every invocation of the template, so the
// above function works with any type `T` that has a const `bark` method!

TEST_CASE("Template Functions") {
    Dog fluffy;
    fluffy.setName("Fluffy");
    barkThreeTimes(fluffy);
}

// Template parameters don't have to be classes
template<int Y>
void printMessage() {
    cout << "Learn C++ in " << Y << " minutes!" << endl;
}

TEST_CASE("Template parameters don't have to be classes") {
    printMessage<1>();
    printMessage<100>();
}

// And you can explicitly specialize templates for more efficient code.
// Of course, most real-world uses of specialization are not as trivial as this.
// Note that you still need to declare the function (or class) as a template
// even if you explicitly specified all parameters.
template<>
void printMessage<10>() {
    cout << "Learn C++ faster in only 10 minutes!" << endl;
}

TEST_CASE("Templates with 'specialization'?") {
    printMessage<10>();
    printMessage<20>();
}

auto add = [](auto x) {
    return [x](auto y) {
        return x + y;
    };
};
auto addone = add(1);

TEST_CASE("Nested Lambdas") {
    REQUIRE(addone(1) == 2);
    REQUIRE(add(1)(1) == 2);
    REQUIRE(add(1)(2) == 3);
}

////////////////////////
// Exception Handling //
////////////////////////

// The standard library provides a few exception types
// (see http://en.cppreference.com/w/cpp/error/exception)
// but any type can be thrown as an exception
#include <exception>
#include <stdexcept>
#include <fstream>

// All exceptions thrown inside the _try_ block can be caught by subsequent
// _catch_ handlers

TEST_CASE("Try/Catch with explicit known catch") {
    try {
        // do not allocate exceptions on the heap using _new_.
        throw std::runtime_error("A problem occurred");
    } catch (const std::exception &ex) {
        std::cout << ex.what() << endl;
    } catch (...) {
        std::cout << "Unknown exception caught" << endl;
        throw; // re-throws exception
    }
}

TEST_CASE("Try/Catch with catch-all") {
    try {
        throw std::domain_error("my domain is in error");
    } catch (...) { // weird that that "..." syntax is legit
        std::cout << "Unknown exception was caught" << endl;
    }
}

//////////
// RAII //
//////////

// RAII stands for "Resource Acquisition is Initialization".
// It is often considered the most powerful paradigm in C++
// and is the simple concept that a constructor for an object
// acquires that object's resources and the destructor releases them.

bool doSomethingWithAFile(const FILE *fh) {
    return true;
}

bool doSomethingElseWithIt(const FILE *fh) {
    return true;
}

// To understand how this is useful,
// consider a function that uses a C file handle
void doSomethingWithAFile(const char *filename) {
    // To begin with, assume nothing can fail
    FILE *fh = fopen(filename, "r"); // Open the file in read mode.

    doSomethingWithAFile(fh);
    doSomethingElseWithIt(fh);

    fclose(fh); // Close the file handle
}

// Unfortunately, things are quickly complicated by error handling.
// Suppose fopen can fail, and that doSomethingWithTheFile and
// doSomethingElseWithIt return error codes if they fail.
// (Exceptions are the preferred way of handling failure,
//  but some programmers, especially those with a C background,
//  disagree on the utility of exceptions).
// We now have to check each call for failure and close the file handle
// if a problem occurred.
bool doSomethingWithAFile2(const char *filename) {
    FILE *fh = fopen(filename, "r"); // Open the file in read mode
    if (fh == nullptr) { // The returned pointer is null on failure
        return false; // report that failure to the caller
    }

    // Assume each function returns false if it failed
    if (!doSomethingWithAFile(fh)) {
        fclose(fh); // close the file handle so it doesn't leak
        return false; // propagate the error
    }
    if (!doSomethingElseWithIt(fh)) {
        fclose(fh); // close the file handle so it doesn't leak
        return false; // propagate the error
    }

    fclose(fh); // close the file handle so it doesn't leak
    return true; // indicate success
}

// C programmers often clean this up a little bit using goto:
bool doSomethingWithAFile3(const char *filename) {
    FILE *fh = fopen(filename, "r");
    if (fh == nullptr) {
        return false;
    }

    if (!doSomethingWithAFile(fh)) {
        goto failure;
    }
    if (!doSomethingElseWithIt(fh)) {
        goto failure;
    }

    fclose(fh);
    return true;

    failure:
    std::cout << "lol I'm in a goto tag thingy" << endl;
    fclose(fh);
    return false;
}

TEST_CASE("Failure handling without exceptions") {
    REQUIRE(doSomethingWithAFile3("Makefile") == true);
    REQUIRE(doSomethingWithAFile3("FILE_THAT_DOES_NOT_EXIST.txt") == false);
}

// If the functions indicate errors using exceptions,
// things are a little cleaner, but still sub-optimal.
void doSomethingWithAFile4(const char *filename) {
    FILE *fh = fopen(filename, "r");
    if (fh == nullptr) {
        throw std::runtime_error("Could not open the file.");
    }
    try {
        doSomethingWithAFile(fh);
        doSomethingElseWithIt(fh);
    } catch (...) {
        fclose(fh);
        throw;
    }

    fclose(fh);
}

// Compare this to the use of C++'s file stream class (fstream)
// fstream uses its destructor to close the file.
// Recall from above that destructors are automatically called
// whenever an object falls out of scope.
void doSomethingWithAFile5(const char *filename) {
    // ifstream is short for input file stream
    std::ifstream fh(filename); // Open the file

    // doSomethingWithAFile(fh);
    // doSomethingElseWithIt(fh);
} // The file is automatically closed here by the destructor

TEST_CASE("Fancy Destructors and Such") {
    doSomethingWithAFile5("Makefile");
}

// This has _massive_ advantages:
// 1. No matter what happens,
//    the resource (in this case the file handle) will be cleaned up.
//    Once you write the destructor correctly,
//    It is _impossible_ to forget to close the handle and leak the resource.
// 2. Note that the code is much cleaner.
//    The destructor handles closing the file behind the scenes
//    without you having to worry about it.
// 3. The code is exception safe.
//    An exception can be thrown anywhere in the function and cleanup
//    will still occur.

// All idiomatic C++ code uses RAII extensively for all resources.
// Additional examples include:
// - Memory using unique_ptr and shared_ptr
// - Containers - the standard library linked list,
//   vector (i.e. self-resizing array), hash maps, and so on
//   all automatically destroy their contents when they fall out of scope.
// - Mutexes using lock_guard and unique_lock

///////////////////
// Smart Pointer //
///////////////////

// Generally a smart pointer is a class which wraps a "raw pointer" (usage of "new"
// respectively malloc/calloc in C). The goal is to be able to manage the lifetime
// of the object being pointed to without ever needing to explicitly delete the object.
// The term itself simply describes a set of pointers with the mentioned abstraction.
// Smart pointers should be preferred over raw pointers, to prevent
// risky memory leaks, which happen if you forget to delete an object.

TEST_CASE("Usage of a raw pointer") {
    Dog *ptr = new Dog();
    ptr->bark();
    delete ptr;
}

// By using a smart pointer, you don't have to worry about the deletion
// of the object anymore.
// A smart pointer describes a policy, to count the references to the pointer.
// The object get destroyed when the last
// reference to the object is destroyed.

void sharedPointerUsageExample() {
    // It's no longer necessary to delete the Dog.
    std::shared_ptr<Dog> doggo(new Dog());
    doggo->bark();
}

TEST_CASE("Usage of std::shared_ptr") {
    sharedPointerUsageExample();
}

TEST_CASE("Beware of possible circular references!") {
    std::shared_ptr<Dog> doggo_one(new Dog());
    std::shared_ptr<Dog> doggo_two(new Dog());
    doggo_one = doggo_two;
    doggo_two = doggo_one;
}

// There are several kinds of smart pointers.
// The way you have to use them is always the same.
// This leads us to the question: when should we use each kind of smart pointer?
// std::unique_ptr - use it when you just want to hold one reference to the object.
// std::shared_ptr - use it when you want to hold multiple references to the
//                   same object and want to make sure that it's deallocated
//                   when all references are gone.
// std::weak_ptr   - use it when you want to access the underlying object
//                   of a std::shared_ptr without causing that object to stay allocated.
//                   Weak pointers are used to prevent circular referencing.

////////////////
// Containers //
////////////////

// Containers or the Standard Template Library are some predefined templates.
// They manage the storage space for its elements and provide
// member functions to access and manipulate them.

// A few containers are as follows:

// Vector (Dynamic array)
// Allow us to Define the Array or list of objects at run time
#include <vector>

TEST_CASE("Vector (Dynamic Array)") {
    string val = "test";
    vector<string> my_vector;
    my_vector.push_back(val);
    my_vector.push_back(val);

    // classic for loop
    cout << "start classic loop" << endl;
    for (int i = 0; i < my_vector.size(); i++) {
        cout << my_vector[i] << endl;
    }
    cout << "end classic loop" << endl;

    // iterator
    cout << "start iterator loop" << endl;
    for (auto it = my_vector.begin(); it != my_vector.end(); ++it) {
        cout << *it << endl;
    }
    cout << "end iterator loop" << endl;
}

#include <set>

TEST_CASE("Sets") {
    // Sets are containers that store unique elements following a specific order.
    // Set is a very useful container to store unique values in sorted order
    // without any other functions or code.

    set<int> ST;
    ST.insert(30);
    ST.insert(10);
    ST.insert(20);
    ST.insert(30);

    for (auto it = ST.begin(); it != ST.end(); it++) {
        cout << *it << endl;
    }

    ST.erase(20);

    for (auto it = ST.begin(); it != ST.end(); it++) {
        cout << *it << endl;
    }

    cout << ST.size() << endl;
    ST.clear();
    cout << ST.size() << endl;
}

#include <map>

TEST_CASE("Maps") {
    map<char, int> mymap;

    mymap.insert(pair<char, int>('A', 1));
    mymap.insert(pair<char, int>('Z', 26));

    map<char, int>::iterator it;
    for (it = mymap.begin(); it != mymap.end(); ++it) {
        std::cout << it->first << "->" << it->second << endl;
    }

    cout << mymap.find('Z')->second << endl;
    cout << mymap.operator[]('Z') << endl;
    cout << mymap['Z'] << endl;
}

// NOTE: For hash maps, use unordered_map. They are more efficient but do
//       not preserve order. unordered_map is available since C++11.

// Containers with object keys of non-primitive values (custom classes) require
// compare function in the object itself or as a function pointer.
// Primitives have default comparators, but you can override it.

class Foo {
public:
    int j;

    Foo(int a) : j(a) {}
};

struct compareFunction {
    bool operator()(const Foo &a, const Foo &b) const {
        return a.j < b.j;
    }
};

TEST_CASE("Custom Comparator") {
    // This isn't allowed (although it can vary depending on compiler)
    // std::map<Foo, int> fooMap;

    std::map<Foo, int, compareFunction> fooMap;
    fooMap[Foo(1)] = 1;
    fooMap.find(Foo(1));
}

//////////////////////////////////////////
// Lambda Expressions (C++11 and above) //
//////////////////////////////////////////

// lambdas are a convenient way of defining an anonymous function
// object right at the location where it is invoked or passed as
// an argument to a function.

// For example, consider sorting a vector of pairs using the second
// value of the pair

TEST_CASE("Lambda Expressions") {
    vector<pair<int, int>> tester;
    tester.push_back(make_pair(3, 6));
    tester.push_back(make_pair(1, 9));
    tester.push_back(make_pair(5, 0));

    REQUIRE(tester.size() == 3);
    REQUIRE(tester[0] == make_pair(3, 6));
    REQUIRE(tester[1] == make_pair(1, 9));
    REQUIRE(tester[2] == make_pair(5, 0));

    // Pass a lambda expression as third argument to the sort function
    // sort is from the <algorithm> header

    sort(tester.begin(), tester.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second < rhs.second;
    });

    REQUIRE(tester.size() == 3);
    REQUIRE(tester[0] == make_pair(5, 0));
    REQUIRE(tester[1] == make_pair(3, 6));
    REQUIRE(tester[2] == make_pair(1, 9));

    // Notice the syntax of the lambda expression,
    // [] in the lambda is used to "capture" variables
    // The "Capture List" defines what from the outside of the lambda should be
    // available inside the function body and how.
    // It can be either:
    //   1. a value : [x]
    //   2. a reference : [&x]
    //   3. any variable currently in scope by reference [&]
    //   4. same as 3, but by value [=]
    // Example:

    vector<int> dog_ids;
    // number_of_dogs = 3;
    for (int i = 0; i < 3; i++) {
        dog_ids.push_back(i);
    }

    REQUIRE(dog_ids.size() == 3);
    REQUIRE(dog_ids[0] == 0);
    REQUIRE(dog_ids[1] == 1);
    REQUIRE(dog_ids[2] == 2);

    int weight[3] = {30, 50, 10};

    // Say you want to sort dog_ids according to the dogs' weights
    // so dog_ids should in the end become: [2, 0, 1]

    // Here's where lambda expressions come in handy

    sort(dog_ids.begin(), dog_ids.end(), [&weight](const int &lhs, const int &rhs) {
        return weight[lhs] < weight[rhs];
    });

    REQUIRE(dog_ids.size() == 3);
    REQUIRE(dog_ids[0] == 2);
    REQUIRE(dog_ids[1] == 0);
    REQUIRE(dog_ids[2] == 1);

    // Note we captured "weight" by reference in the above example.
    // More on Lambdas in C++ : http://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
}

/////////////////////////////////
// Range For (C++11 and above) //
/////////////////////////////////

TEST_CASE("Range For") {
    // You can use a range for loop to iterate over a container
    int arr[] = {1, 10, 3};

    for (int elem: arr) {
        cout << elem << endl;
    }

    // You can use "auto" and not worry about the type of the elements of the container
    // For example:
    for (auto elem: arr) {
        cout << elem << endl;
    }
}

///////////////
// Fun Stuff //
///////////////

// Aspects of C++ that may be surprising to newcomers (and even some veterans).
// This section is, unfortunately, wildly incomplete; C++ is one of the easiest
// languages with which to shoot yourself in the foot.

TEST_CASE("Override private methods!") {
    class Foo {
        virtual void bar();
    };
    class FooSub : public Foo {
        virtual void bar(); // Overrides Foo::bar!
    };
}

TEST_CASE("Strange equalities") {
    // 0 == false == NULL (most of the time)
    bool *pt = new bool;
    *pt = 0;
    pt = 0;

    // nullptr is supposed to fix some of that issue:
    int *ptr2 = new int;
    // *ptr2 = nullptr; // doesn't compile
    ptr2 = nullptr;

    // There is an exception made for bools.
    // This is to allow you to test for null pointers with if(!ptr),
    // but as a consequence you can assign nullptr to a bool directly!
    // *pt = nullptr; // compiles, but causes a SIGSEGV

    // '=' != '=' != '=' !
    // Calls Foo::Foo(const Foo&) or some variant (see move semantics) copy constructor
    class Foo {
    };
    class FooSub : public Foo {
    };

    Foo f2;
    Foo f1 = f2;

    // Calls Foo::Foo(const Foo&) or variant, but only copies the 'Foo' part of
    // 'fooSub'. Any extra members of 'fooSub' are discarded.
    // This sometimes horrifying behavior is called "object slicing".

    FooSub fooSub;
    Foo f3 = fooSub;

    // Calls Foo::operator=(Foo&) or variant.
    Foo f4;
    f4 = f2;
}

//////////////////////////////
// Tuples (C++11 and above) //
//////////////////////////////

#include <tuple>

// Conceptually, Tuples are similar to old data structures (C-like structs)
// but instead of having named data members,
// its elements are accessed by their order in the tuple.

// We start with constructing a tuple.
// Packing values into tuple

TEST_CASE("Tuples") {
    auto first = make_tuple(10, 'A');
    const int maxN = 1e9;
    const int maxL = 15;
    auto second = make_tuple(maxN, maxL);

    // Printing elements of 'first' tuple
    cout << get<0>(first) << " " << get<1>(first) << endl;

    // Printing elements of 'second' tuple
    cout << get<0>(second) << " " << get<1>(second) << endl;

    // how to make a generic function that prints a tuple regardless of the types
    // in that tuple?
//    auto ptuple[](tuple a) {
//        cout << get<0>(a) << " " << get<1>(a) << endl;
//    };

//    template<class T>
//    void printTuple(const T &input) {
//        cout << get<0>(a) << " " << get<1>(a) << endl;
//    }

//    printTuple(first);
//    printTuple(second);

    int first_int;
    char first_char;
    tie(first_int, first_char) = first;
    cout << first_int << " " << first_char << endl;

    // We can also create tuple like this.
    tuple<int, char, double> third(11, 'A', 3.14141);

    cout << tuple_size<decltype(third)>::value << endl;

    auto concatenated_tuple = tuple_cat(first, second, third);

    cout << get<0>(concatenated_tuple) << endl;
    cout << get<3>(concatenated_tuple) << endl;
    cout << get<5>(concatenated_tuple) << endl;
}

///////////////////////////////////
// Logical and Bitwise Operators //
///////////////////////////////////

// Most of the operators in C++ are smae as in other languages

// Logical operators

// C++ uses short-ciruit evalution for boolean expressions, i.e.,
// the second argument is executed or evaluated only if the first argument
// does not suffice to determine the value of the expression

TEST_CASE("Logical Operators") {
    REQUIRE((true && false) == false);
    REQUIRE((true || false) == true);
    REQUIRE((!true) == false);

    // keywords are a thing in C++ too (instead of just using the symbols)
    REQUIRE((true and false) == false);
    REQUIRE((true or false) == true);
    REQUIRE((not true) == false);
}

TEST_CASE("Bitwise Operators") {
    // **<<** Left Shift Operator
    // << shifts bits to the left
    REQUIRE((4 << 1) == 8); // Shifts bits of 4 to left by 1 to give 8
    // x << n can be thought as x * 2^n

    // **>>** Right Shift Operator
    // >> shifts bits to the right
    REQUIRE((4 >> 1) == 2); // Shifts bits of 4 to the right by 1 to give 2
    // x >> n can be thought as x / 2^n

    // Bitwise operators
    REQUIRE((~4) == -5); // bitwise not (also, what the fuck?)
    REQUIRE((4 | 3) == 7); // bitwise or
    REQUIRE((4 & 3) == 0); // bitwise and
    REQUIRE((4 ^ 3) == 7); // bitwise xor

    // Equivalent bitwise keywords
    REQUIRE((compl 4) == -5);    // bitwise not
    REQUIRE((4 bitor 3) == 7);  // bitwise or
    REQUIRE((4 bitand 3) == 0); // bitwise and
    REQUIRE((4 xor 3) == 7);    // bitwise xor
}
