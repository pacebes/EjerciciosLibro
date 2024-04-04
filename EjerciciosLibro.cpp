import Vector; // get Vector's interface
import Complejo; 
#include <cmath> // get the standard-library math function interface including sqrt()
#include <locale.h>
#include <windows.h> 
#include <filesystem>
#include <vector> 
#include <string> 
#include <map> 
#include <complex> 
#include <list> 
#include <stdexcept>
#include <regex>
#include <fstream>
#include <iostream> 
#include <chrono>
#include <thread>
#include <string_view>
#include <syncstream> 
#include <bitset>
#include <functional>
#include <numeric>
#include <random>
#include <coroutine>
#include "ficheroPrueba.h"

using namespace std; 
/* 
* Sobre cómo matar procesos
* 
taskkill / f / t / PID 13788

wmic process where "name='EjerciciosLibro.exe'" delete
taskkill / f / t / IM "EjerciciosLibro.exe"
https://techcommunity.microsoft.com/t5/windows-blog-archive/unkillable-processes/ba-p/723389
*/


double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
        sum += std::sqrt(v[i]); // sum of square roots
    return sum;
}

void libroantesde345()
{
    Vector testVector(4);
    testVector[0] = 0.0;
    testVector[1] = 1.1;
    testVector[2] = 2.2;
    testVector[3] = 3.3;

    using namespace std;
    cout << "Ejemplo vector y módulo " << sqrt_sum(testVector) << endl;

    funcionPrueba();

    int llamadaMainExterna = My_code::main();

    vector fib = { 1, 2, 3, 5, 8, 13, 21 };

    cout << "Suma de vectores es " << sum(fib) << endl;
}

void libro345()
{
    using namespace std;

    map<string, int> m;

    m = { {"uno",1}, {"dos", 2}};

    // ... fill m ...
    for (const auto [key, value] : m)
        cout << "{" << key << "," << value << "}\n";

    complex<double> z1 = { 1,2 };
    complex<double> z2 = { 2,4 };
    complex<double> z3 = z1+z2;
    // auto [re, im] = z3 ; 

    cout << z3;

    /* 
    cout << "Dame nombre y valor, ¡ leñe !: \n";

    auto e = read_entry345(cin);

    cout << "{ " << e.name << " , " << e.value << " }\n";

    cout << "Dame de nuevo nombre y valor, ¡ leñe !: \n";
    auto [n, v] = read_entry345(cin);
    cout << "{ " << n << " , " << v << " }\n";
    */

}


void test43(int n)
{
    std::cout << "Probando con el valor de entrada " << n << std::endl;

    try {
        Vector v(n);
    }
    catch (std::length_error& err) {
        // ... handle negative size ...
        std::cerr << "handle negative size\n" << err.what() <<std::endl;
        throw; // rethrow y al no 
    }
    catch (std::bad_alloc& err) {
        // ... handle memory exhaustion ...
        std::cerr << "handle memory exhaustion\n" << err.what() << std::endl;
    }
}

void libro43()
{
    
    test43(-27); // throws length_error (-27 is too small)
    test43(1000000000); // may throw bad_alloc
    test43(10);
}


void libro521()
{
    using namespace std;
    complex comp1(1.0, 5.0), comp2(4.0, 6.9999), comp3(0.0,0.0), comp4(0.0, 0.0);
    comp3 = comp1 + comp2;
    comp4 = comp1 * comp2;
    cout << comp3.real() << " " << comp3.imag() << endl;
    cout << comp4.real() << " " << comp4.imag() << endl;
}

Vector read523(std::istream& is)
{
    Vector v;
    for (double d; is >> d; ) // read floating-point values into d
        v.push_back(d); // add d to v
    return v;
}

void libro523()
{
    using namespace std;

    Vector v1 = { 1, 2, 3, 4, 5 }; // v1 has 5 elements
    Vector v2 = { 1.23, 3.45, 6.7, 8 }; // v2 has 4 elements
    Vector v = read523(cin); // no copy of Vector elements here

    cout << v.size() << " " << v[0] << endl;
}

void libro61()
{
    using namespace std;
    /*
    Complejo z1 (3.14,0.0 ); // z1 becomes {3.14,0.0}

    Complejo z2{ z1 }; // copy initialization
    Complejo z3;
    z3 = z2;
     */

    Vector v1 = { 1, 2, 3, 5, 8, 13, 21 };
    Vector v2 = v1; // Constructor de copia 
    Vector v3 = std::move(v1); // Constructor Move
    Vector v4 = v2;

    if (v2.size()) {
        cout << " v2 " << v2.size() << " " << v2[0] << endl;
    }
    if (v1.size()) {
        cout << " v1 " << v1.size() << " " << v1[0] << endl;
    }   
    
    cout << " v3 " << v3.size() << " " << v3[0] << endl;
}

Vector init63(int n)
{
    using namespace std;
    /* 
    std::vector<thread> my_threads;
    std::thread t{ 1 }; // run heartbeat concurrently(in a separate thread)
    my_threads.push_back(std::move(t)); // move t into my_threads(§16.6)
        // ... more initialization ...
    */ 
    Vector vec(n);
    //for (auto& x : vec)
    for (int i=0; i!=vec.size();++i)
        vec[i] = 777;
    return vec; // move vec out of init()
}

void libro63()
{
    using namespace std;
    auto v = init63(10); // start heartbeat and initialize v
    cout << "Tamaño " << v.size() << ". Valor del 1º: " << v[0] << endl;


    int i = 2, j = 4;

    cout << "i " << i << " j " << j << endl;
    i = i << 2;
    j = j << 2;
    cout << "i " << i << " j " << j << endl;
    complex<double> z = 2.7182818 + 6.283185i;
}

void libro71_a2()
{
    using namespace std;

    vector<char> vc(200); // vector of 200 characters
    vector<string> vs(17); // vector of 17 strings
    // vector<list<int>> vli(45); // vector of 45 lists of integers

    vs[0] = "cero"; vs[1] = "uno";

    for (auto& s : vs)
        cout << s << '\n';

    pair<int, double> p = { 1, 5.2 };

    cout << p.first << " " << std::get<0>(p) << " " << p.second << endl;

    vector vs3{ "Hello"s, "World"s };
    vector<string> vs4{ "Hello"s, "World" };

    vector v11{ 1, 2, 3, 4, 5 }; // element type is int
    vector v12(v11.begin(), v11.begin() + 3); // Coge los 3 primeros (1,2,3)


    cout << "vs4 " << vs4[0] << " " << vs4[1] << " " << endl;

    cout << "v12 " << *(v11.begin()+3) << " " << v12[0] << " " << v12[1] << " " << v12[2] << " " << endl;

}

template<typename Sequence, typename Value>
  Value sum73(const Sequence& s, Value v)
{
    for (const auto& x : s)
        v += x;
    return v;
}

void testLibro73(std::list<double>& ld)
{
    using namespace std;

    // int x = sum73(vi, 0); // the sum of a vector of ints(add ints)
    // double d = sum73(vi, 0.0); // the sum of a vector of ints(add doubles)
    double dd = sum73(ld, 0.0); // the sum of a list of doubles
    
    cout << "Suma de la lista de dobles: " << dd << endl;
    //auto z = sum73(vc, complex{ 0.0,0.0 }); // the sum of a vector of    complex<double>s
}

void f73(const std::vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
    using namespace std;
    cout << "number of values less than " << x << ": " <<
        count(vec, Less_than{ x }) << '\n';
    cout << "number of values less than " << s << ": " <<
        count(lst, Less_than{ s }) << '\n';

    // The notation[&](int a) { return a < x; } is called a lambda expression
    cout << "number of values less than " << x
        << ": " << count(vec, [&](int a) { return a < x; }) << '\n';
    cout << "number of values less than " << s
        << ": " << count(lst, [&](const string& a) { return a < s; }) << '\n';

    // The[&] is a capture list specifying that all local names used in the lambda body (such as x) will be accessed through references.Had we wanted to
    // “capture” only x, we could have said so : [&x] .Had we wanted to give the generated object a copy of x, we could have said so : [x] .Capture
    // nothing is[], capture all local names used by reference is[&], and capture all local names used by value is[=].
    // 
    // For a lambda defined within a member function, [this] captures the current object by reference so that we can refer to class members.
    // If we want a copy of the current object, we say[*this].If we want to capture several specific objects, we can list them.
    
}

void libro73()
{
    using namespace std;

    list<double> ld = { 1.1, 2.2,3.3 };

    testLibro73(ld);

    Less_than lti{ 42 }; // lti(i) will compare i to 42 using < (i < 42)
    Less_than lts{ "Backus"s }; // lts(s) will compare s to "Backus" using < (s < "Backus")
    Less_than<string> lts2{ "Naur" }; // "Naur" is a C-style string, so we need <string> to get the right <

    lti(90) ? cout << "Menor " << endl : cout << "Mayor o igual" << endl;
    lts2("Maná") ? cout << "Menor " << endl : cout << "Mayor o igual" << endl;
    lts2("ZZZZ") ? cout << "Menor " << endl : cout << "Mayor o igual" << endl;
    
}

void libro8()
{
    // bool b0 = cmp(cout, cerr); // error: ostream doesn't support ==
    bool b1 = compara(2, 3); // OK: returns true
    // bool b2 = compara(2 + 3i, 3 + 4i); // error: complex<double> doesn't support

    imprimeTemp("Hola ", 33, "Adios", 4.55665, "\n", "más", "Menos"s);

}

void libro9()
{
    // auto c2 = 1.0 + 3.0std::complex_literals::i;
    // To use the s suffix, you need to use the namespace std::literals::string_literals(§6.6).
    auto cat = "Cat"s;

    // using namespace literals::complex_literals; // Esto NO FUNCIONA EN VISUAL C++
    using namespace std::complex_literals;
    auto c1 = 1.0 + 3.0i;
    
    std::cout << "c1 = " << c1 << '\n';   

}

string cat10(string_view sv1, string_view sv2)
{
    string res{ sv1 }; // initialize from sv1
    return res += sv2; // append from sv2 and return
}

void libro10()
{

    string king = "Harold";
    auto s1 = cat10(king, "William"); // HaroldWilliam: string and    const char*
    auto s2 = cat10(king, king); // HaroldHarold: string and    string
    auto s3 = cat10("Edward", "Stephen"sv); // EdwardStephen: const    char* and string_view
    auto s4 = cat10("Canute"sv, king); // CanuteHarold
    auto s5 = cat10({ &king[0],2 }, "Henry"sv); // HaHenry
    auto s6 = cat10({ &king[0],2 }, { &king[2],4 }); // Harold

    /* Why bother with a suffix? The reason is that when we pass "Edward"
    we need to construct a string_view from a const char* and that
    requires counting the characters. For "Stephen"sv the length is
    computed at compile time.
    */

    cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 << endl;

    
}

void libro10Regexp()
{
     std::filesystem::path cwd = std::filesystem::current_path();
     cout << "Directorio actual: " << cwd << endl;
     
     const string fichMat = "ficheroMatriculas.txt";
    
    ifstream in(fichMat); // input file
    if (!in) { // check that the file was opened
        cerr << "no file\n";
        return;
    }
    //    regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" }; 
    // regex pat{ R"(\d{4}(-?)\w{3})" }; // Matrícula
    // regex pat{ R"(\d{4}(-?)\w{3-4})" }; // Matrícula con 3 o 4 letrasa{m} 
    // exactly m a’s
    // a{ m, } - at least m a’s
    // a{ m,n } - at least m but at most n a’s
    // 3 o 4 dígitos / ^ [0 - 9] {3, 4}$ /
        
    // regex pat{ R"(\d{4}(-?)[a-z]{3})" }; // Matrícula
    regex pat{ R"(\d{4}(?:-?)[A-Za-z]{3})" }; // Matrícula
          
    int lineno = 0;
    bool encontrado = false;
    
    for (string line; getline(in, line); ) {
        ++lineno;
        smatch matches; // matched strings go here
        
        string::const_iterator buscarDesde(line.cbegin()); 
        while (regex_search(buscarDesde, line.cend(),  matches, pat)) {
            encontrado = true;
            cout << lineno << ": " << matches[0] << '\n'; // the complete match
            if (1 < matches.size() && matches[1].matched) // if there is a sub - pattern
                // and if it is matched
                cout << "\t: " << matches[1] << '\n'; //  submatch
            buscarDesde = matches.suffix().first;
        }
    }

    if (!encontrado)
        cout << "No se ha encontrado ninguna matrícula en el fichero " << fichMat << " del directorio " << cwd << endl;

}

vector<int> read_ints11(istream& is, const string& terminator)
{
    vector<int> res;
    for (int i; is >> i; )
        res.push_back(i);
    if (is.eof()) // fine: end of file        
        return res;
    if (is.fail()) { // we failed to read an int; was it the        terminator ?
        is.clear(); // reset the state to good()
        string s;
        if (is >> s && s == terminator)
            return res;
        is.setstate(ios_base::failbit); // add fail() to is's state
    }
    return res;
}

void test11(std::filesystem::path p)
{
    using namespace filesystem;

    if (is_directory(p)) {
        cout << p << ":\n";
        for (const directory_entry& x : directory_iterator(p)) {
            const path& f = x; // refer to the path part of a directory            entry
            if (f.extension() == ".exe")
                cout << f.stem() << " is a Windows executable\n";
            else {
                string n = f.extension().string();
                if (n == ".cpp" || n == ".C" || n == ".cxx")
                    cout << f.stem() << " is a C++ source file\n";
            }
        }
    }
}

void libro11()
{
    ios_base::sync_with_stdio(false); // avoid significant overhead

    /*
    vector<int> vectorEnteros = read_ints11(cin,"para");

    for ( auto s : vectorEnteros)
    {
        cout << s << " ";
    }

    for (Entry11 ee; cin >> ee; ) // read from cin into ee
        cout << ee << '\n'; // write ee to cout

    using namespace chrono;
    cout << "birthday: " << 11 / 12 / 2021 << '\n';
    cout << "zt: " << zoned_time{ current_zone(), system_clock::now() } << '\n';
    cout << format("{} {:x} {:o} {:d} {:b}\n", 1234, 1234, 1234, 1234, 1234);
    cout << format("{3:} {1:x} {2:o} {0:b}\n", 000, 111, 222, 333);
    cout << format("{0:} {0:x} {0:o} {0:d} {0:b}\n", 1234, 1234.5678 );
    cout << format("{0:}; {0:e}; {0:a}; {0:f}; {0:g}\n", 123.456); 
    cout << format("{0:} {0:x} {0:o} {0:d} {0:b} {1:.3}; {1:e}; {1:a}; {1:f}; {1:g}\n", 1234, 1234.5678);

    auto ymd = 2021y / March / 30;
    cout << ymd.year() << ymd.month() << ymd.day() << weekday(ymd);
    // cout << format("ymd: {3:%A},{1:} {2:%B},{0:}\n", ymd.year(), ymd.month(), ymd.day(), weekday(ymd));

    ostringstream oss;
    oss << "{temperature," << scientific << 123.4567890 << "}";
    cout << oss.view() << '\n';

    osyncstream osss(cout);
    osss << 345;
    osss << "Perico"sv;

    cout << std::endl; // It's the same as the next line
    cout << '\n' << std::flush; 
 */

    test11(".");

}

void test13except()
{

    try
    {
        auto result = DivideByZeroException::divide(5, 5);
        result = DivideByZeroException::divide(5, 0);

        cout << "\nThe two numbers divided are " << result << endl;
    }
    catch (const DivideByZeroException& e)
    {
        cout << "Muero" << endl;
        cout << e.what() << endl;
    }
}

void test14listas()
{
    string m{ "Mary had a little lamb" };
    for (auto p : find_all(m, 'a')) // p is a string::iterator
        if (*p != 'a')
            cerr << "string bug!\n";
    list<int> ld{ 1, 2, 3, 1, -11, 2 };
    for (auto p : find_all(ld, 1)) // p is a       list<int>::iterator
        if (*p != 1)
            cerr << "list bug!\n";
    vector<string> vs{ "red", "blue", "green", "green", "orange", "green" };

    for (auto p : find_all(vs, "red")) // p is a vector<string>::iterator
    {
        if (*p != "red")
        {
            cerr << "vector bug!\n" << endl;
        }
        else
        {
            cout << "Tudo bem!\n";
        }
    }
    for (auto p : find_all(vs, "green"))
        *p = "vert";


}

void test14x0()
{
  ostream_iterator<string> oo{ cout }; // write strings to cout
  vector<string> v{ "¡ Buenos días ", " sean dados !", " a todo el mundo\n" };
  ranges::copy(v, oo); 
  std::copy(v.begin(), v.end(), oo);


}


void test14x1()
{
    auto r = ranges::iota_view(42, 52);
    for (int x : r) // 42 43 44 45 46 47 48 49 50 51
        cout << x << ' ';

    cout << "\n";

    auto odd = [](int x) { return x % 2; };
    for (int x : r | views::filter(odd) | views::take(4))
        cout << x << ' ';

    cout << "\n";

    /* 
    const char aa[] = "Hello, World!\nBye for now\n";
    ranges::for_each(aa, Sentinel<const char*>('\n'), [](const char x) {
        cout << x; });

    */
}

void fs151(span<int> p)
{
    int numElementos = 0;
    for (int& x : p) {
        x = 0;
        ++numElementos;
    }
    cout << "Número de elementos: " << numElementos << "\n";
}


template <size_t N = 0, typename... Ts>
constexpr void print151(tuple<Ts...> tup)
{
    if constexpr (N < sizeof...(Ts)) { // not yet at the end?
        cout << get<N>(tup) << ' '; // print the Nth element
        print151<N + 1>(tup); // print the next element
    }
}

void test151(int x)
{
    int a[100];
    fs151(a); // implicitly creates a span<int>{a,100}
    // fs151(a, 1000); // error: span expected
    // fs151({ a + 10,100 }); // a range error in fs
    // fs151({ a,x }); // obviously suspect
    array<int, 4> a1 = { 1,2,3, 4 };

    bitset<9> bs1{ "110001111" };
    bitset<9> bs2{ 0b1'1000'1111 };

    cout << bs1 << "---" << bs2 << "\n";

    tuple t0{}; // empty
    tuple<string, int, double> t1{ "Shark",123,3.14 }; // the type is explicitly specified
    auto t2 = make_tuple(string{ "Herring" }, 10, 1.23); // the type is deduced to tuple<string, int, double>
    tuple t3{ "Cod"s,20,9.99 }; // the type is deduced to tuple<string, int, double>
    print151(t0); // no output
    print151(t2); // Herring 10 1.23
    print151(tuple{ "Norah", 17, "Gavin", 14, "Anya", 9, "Courtney", 9,    "Ada", 0 });
}

void test161()
{
    /*
    using namespace std::chrono; // in sub-namespace std::chrono;    see §3.3
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    auto t0 = system_clock::now();
    std::this_thread::sleep_for(nanoseconds(10000000));
    auto t1 = system_clock::now();

    cout << t1 - t0 << "\n"; // default unit: 20223[1 / 100000000]s
    cout << duration_cast<milliseconds>(t1 - t0).count() << "ms\n";   // specify unit: 2ms
    cout << duration_cast<nanoseconds>(t1 - t0).count() << "ns\n";   // specify unit: 2022300ns

    sys_days t = sys_days{ February / 25 / 2022 }; // get a time point with the precision of days
    t += days{ 7 }; // one week after    February 25, 2022
    auto d = year_month_day(t); // convert the time point    back to the calendar
    cout << d << '\n'; // 2022-   03 - 04
    cout << format("{}/{:%B}/{}\n", d.day(), d.month(),  d.year()); //   March / 04 / 2022

    auto p = make_unique<int>(2);
    // auto q = p; // error: we can't copy a unique_ptr
    auto r = move(p); // p now holds nullptr
    */

    double val = 7.2;
    auto x = bit_cast<uint64_t>(val); // get the bit representation of a 64 - bit floating point number
    auto y = bit_cast<uint64_t>(&val); // get the bit representation of a 64- bit pointer

    cout << format("{0:x} {0:o} {0:d} {0:b} \n", x); 
    cout << format("{0:f}; {0:g}; \n", val); 
    cout << format("{0:x} {0:o} {0:d} {0:b} \n", y);
       

}

void test171()
{
    /*    std::vector<int> a{1, 2};
        std::vector<int> b{ 3, 5 };

        int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
        int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 10);
        std::cout << "Inner product of a and b: " << r1 << " " << r2 << '\n';

        using my_engine = default_random_engine; // type of     engine
        using my_distribution = uniform_int_distribution<>; // type of    distribution
        my_engine eng{}; // the default    version of the engine
        my_distribution dist{ 1,600 }; // distribution    that maps to the ints 1..6
        auto die = [&]() { return dist(eng); }; // make a    generator
        int x = die(); // roll the die: x    becomes a value in[1:6]

        cout << x << "\n";
        */

    constexpr int max = 9;
    Rand_int rnd{ 0,max }; // make a uniform random number generator
    vector<int> histogram(max + 1); // make a vector of appropriate size
    for (int i = 0; i != 200; ++i)
        ++histogram[rnd()]; // fill histogram with the frequencies of numbers[0:max]
    for (int i = 0; i != histogram.size(); ++i) { // write out a bar graph
        cout << i << '\t';
        for (int j = 0; j != histogram[i]; ++j) cout << '*';
        cout << '\n';
    }

}

void f181(vector<double>& v) // function
{
    using namespace std::chrono; // in sub-namespace std::chrono;    see §3.3
    osyncstream oss(cout);

    oss << "f181 1" << "\n";
    std::this_thread::sleep_for(nanoseconds(1000));
    oss << "f181 2" << "\n";
}
struct F181 { // function object
    vector<double>& v;
    F181(vector<double>& vv) :v{ vv } { }
    void operator()() {
        using namespace std::chrono; // in sub-namespace std::chrono;    see §3.3
        osyncstream oss(cout);

        oss << "F181 1" << "\n";
        std::this_thread::sleep_for(nanoseconds(1000));
        oss << "F181 2" << "\n";
    }; // F's call operator (§7.3.2)
};

void test181()
{
    vector<double> some_vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<double> vec2{ 10, 11, 12, 13, 14 };

    jthread jt1{ f181, ref(some_vec) }; // f() executes in separate thread
    jthread jt2{ F181{vec2} }; // F{}() executes in separate thread
}


void test182()
{
    vector<Event_base*> events = { // create a couple of     Events holding coroutines
    new Event{ "integers ", sequencer(10) },
    new Event{ "chars ", char_seq('a') }, 
    new Event{ "strings ", string_seq("aaa") }
    };

    vector order{ 0, 1, 1, 0, 1, 0, 1, 0, 0, 2, 2, 2, 1, 0 }; // choose some     order
    for (int x : order) // invoke coroutines            in order
        (*events[x])();
    for (auto p : events) // clean up
        delete p;
}
void enEspañol()
{
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(CP_UTF8); // Cambiar STDIN -  NO FUNCIONA PARA ESPAÑOL
    SetConsoleOutputCP(CP_UTF8); // Cambiar STDOUT - NO FUNCIONA PARA ESPAÑOL

    SetConsoleCP(1252); // Cambiar STDIN -  Sí funciona para español: página 1252 ( "Latin 1 Western Europe")
    SetConsoleOutputCP(1252); // Cambiar STDOUT -  Sí funciona para español: página 1252 ( "Latin 1 Western Europe")

}

int main(int argc, char* argv[])
{
    using namespace std;

    enEspañol();

    // libroantesde345();
    // libro345();
    /*
    try {
        libro43();
    }
    catch (std::length_error& err) {
        std::cerr << "Capturada la excepción relanzada desde el punto anterior\n" << err.what() << std::endl;
    }
    */
    // libro521();
    // libro523();
    // Container* p = new Vector_container(10); // OK: Container is an interface for Vector_container
    // libro61();
    // libro63();
    // libro71_a2();
    // libro73();
    // libro8();
    // libro9();
    // libro10();
    // libro10Regexp();
    // libro11();
    // test13except();
    // test14listas();
    // test14x0();
    // test14x1();
    // test151(156);
    // test161();
    // test171();
    /*
    for (int i = 0; i < 10; ++i)
    {
        test181();
    }
    */
    test182();

    cout << "Parche ejemplo con GIT en un rama (parte1) \n";

    cout << "Parche ejemplo con GIT en un rama (parte2) \n";

    cout << "Mensaje en la rama principal \n";

    cout << "Mensaje 1 parche 2\n";


}
