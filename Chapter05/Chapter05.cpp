// Chapter05.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#include "words.h"
#include "student_info.h"
#include "permuted_index.h"

using std::cin;     using std::cout;    using std::endl;
using std::string;  using std::ifstream;
using std::vector;  using std::stringstream;
using std::list;    using std::chrono::steady_clock;

void test_string_split() {
  string s;

  while (getline(cin, s)) {
    vector<string> v = split(s);

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;
  }
}

void test_input_split() {
  string s;
  
  while (cin >> s)
    cout << s << endl;
}

void test_frame() {
  vector<string> v1 = { "one test", "two test", "aye caramba" };
  vector<string> v2 = { "one direction", "mama mia", "mamo testo", "lake district mall" };

  vector<string> vert = vcat(frame(v1), frame(v2));

  vector<string>::const_iterator iter = vert.begin();

  while (iter != vert.end())
    cout << *iter++ << endl;

  vector<string> horz = hcat(frame(v1), frame(v2));

  iter = horz.begin();

  while (iter != horz.end())
    cout << *iter++ << endl;
}

void test_frame2() {
  vector<string> v;
  vector<string> v_framed = frame(v);

  vector<string>::const_iterator iter = v_framed.begin();

  while (iter != v_framed.end())
    cout << *iter++ << endl;
}

void test_permuted_index() {
  vector<string> v = { "The quick brown fox", "jumped over the fence" };
  vector<string> permuted_v = permuted_index(v);

  vector<string>::const_iterator iter = permuted_v.begin();

  while (iter != permuted_v.end())
    cout << *iter++ << endl;
}

void test_center() {
  vector<string> v = { "This is really great", "really", "super awesome", "awesomesauce" };
  vector<string> centered_v = center(v);

  vector<string>::const_iterator iter = centered_v.begin();

  while (iter != centered_v.end())
    cout << *iter++ << endl;
}

vector<Student_info> test_student_info(string file, vector<Student_info>& s) {

  ifstream infile;
  vector<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
  infile.close();
  infile.clear();

  vector<Student_info> s_copy = s;

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

  failed.clear();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails_v2(s_copy);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed with resize method from " << file << " student vector = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

  return failed;
}

list<Student_info> test_student_info(string file, list<Student_info>& s) {

  ifstream infile;
  list<Student_info> failed;

  infile.open(file);
  steady_clock::time_point begin = std::chrono::steady_clock::now();
  read(infile, s);
  steady_clock::time_point end = std::chrono::steady_clock::now();
  cout << "Microseconds to read " << file << " into list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
  infile.close();
  infile.clear();

  begin = std::chrono::steady_clock::now();
  failed = extract_fails(s);
  end = std::chrono::steady_clock::now();
  cout << "Microseconds to extract failed from " << file << " student list = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

  return failed;
}

void test_student_info(string amount) {
  string file = "students" + amount + ".txt";
  ifstream infile;

  typedef list<Student_info> students_t;
  students_t students;
  students_t students_f;

  students_f = test_student_info(file, students);
}

void test_student_info() {
  test_student_info("10");
  test_student_info("100");
  test_student_info("1000");
  test_student_info("10000");
}

void test_words_lower_upper() {
  vector<string> words = { "TEST" , "test" , "mountain", "BIKE", "six", "seven", "EIGHT", "NINE", "ten" };
  write_lower_upper(cout, words);
}

void test_palindromes() {
  vector<string> words = { "TEST" , "teet" , "racecar", "BIKE", "six", "madam", "EIGHT", "reDder", "ten" };
  write_palindromes(cout, words);
}

void test_ascender_descender() {
  list<string> words = { "TEST" , "teet" , "racecar", "BIKE", "six", "madam", "EIGHT", "reDder", "ten", "multilangual" };
  cout << longest_not_asc_desc(words) << endl;
}

int main()
{
  test_ascender_descender();
  return 0;
}