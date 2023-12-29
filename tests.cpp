#include <gtest/gtest.h>
#include "mymap.h"
#include "myrandom.h"

// one is default constructor
TEST(mymap, one) {
  // check for default constructor for all type
  
  // first int type
  mymap<int, int> map_1;
  EXPECT_EQ(map_1.Size(), 0);
  mymap<int, double> map_2;
  EXPECT_EQ(map_2.Size(), 0);
  mymap<int, char> map_3;
  EXPECT_EQ(map_3.Size(), 0);
  mymap<int, bool> map_4;
  EXPECT_EQ(map_4.Size(), 0);
  mymap<int, string> map_5;
  EXPECT_EQ(map_5.Size(), 0);
  
  
  // second double type
  mymap<double, double> map_6;
  EXPECT_EQ(map_6.Size(), 0);
  mymap<double, int> map_7;
  EXPECT_EQ(map_7.Size(), 0);
  mymap<double, char> map_8;
  EXPECT_EQ(map_8.Size(), 0);  
  mymap<double, bool> map_9;
  EXPECT_EQ(map_9.Size(), 0);  
  mymap<double, string> map_10;
  EXPECT_EQ(map_10.Size(), 0);  
  
  // third char type
  mymap<char, double> map_11;
  EXPECT_EQ(map_11.Size(), 0);  
  mymap<char, int> map_12;
  EXPECT_EQ(map_12.Size(), 0);  
  mymap<char, char> map_13;
  EXPECT_EQ(map_13.Size(), 0);  
  mymap<char, bool> map_14;
  EXPECT_EQ(map_14.Size(), 0);  
  mymap<char, string> map_15;
  EXPECT_EQ(map_15.Size(), 0);  
  
  // fourth string type
  mymap<string, double> map_16;
  EXPECT_EQ(map_16.Size(), 0);  
  mymap<string, int> map_17;
  EXPECT_EQ(map_17.Size(), 0);  
  mymap<string, char> map_18;
  EXPECT_EQ(map_18.Size(), 0);   
  mymap<string, bool> map_19;
  EXPECT_EQ(map_19.Size(), 0);   
  mymap<string, string> map_20;
  EXPECT_EQ(map_20.Size(), 0);  
  
  // fifth bool type
  mymap<bool, double> map_21;
  EXPECT_EQ(map_21.Size(), 0);   
  mymap<bool, int> map_22;
  EXPECT_EQ(map_22.Size(), 0);   
  mymap<bool, char> map_23;
  EXPECT_EQ(map_23.Size(), 0);   
  mymap<bool, bool> map_24;
  EXPECT_EQ(map_24.Size(), 0);  
  mymap<bool, string> map_25;
  EXPECT_EQ(map_25.Size(), 0);  
}

// test two is to test the put
TEST(mymap, two){
  // int type
  mymap<int, int> map_1;
  int arr[] = {2, 1, 3};
  for(int i=0; i < 3;  i++){
    map_1.put(arr[i], arr[i]);
  }
  EXPECT_EQ(map_1.Size(), 3);
  
  mymap<int, int> map_1_1;
  int arr_1[] = {1, 6, 3};
  for(int i=0; i < 3;  i++){
    map_1_1.put(arr_1[i], arr_1[i]);
  }
  EXPECT_EQ(map_1_1.Size(), 3);
  
  mymap<int, int> map_1_2;
  int arr_2[] = {1, 6, 3, 7, 9};
  for(int i=0; i < 5;  i++){
    map_1_2.put(arr_2[i], arr_2[i]);
  }
  EXPECT_EQ(map_1_2.Size(), 5);  
  
  mymap<int, int> map_1_3;
  int arr_3[] = {3, 4, 1, 2, 8};
  for(int i=0; i < 5;  i++){
    map_1_3.put(arr_3[i], arr_3[i]);
  }
  EXPECT_EQ(map_1_3.Size(), 5); 
  
  // char type
  mymap<char, char> map_13;
  char arr_13[] = {'a', 'b', 'c'};
  for(int i=0; i < 3;  i++){
    map_13.put(arr_13[i], arr_13[i]);
  }
  EXPECT_EQ(map_13.Size(), 3);
  
  // string type
  mymap<string, string> map_20;
  string arr_20[] = {"first", "second", "third"};
  for(int i=0; i < 3;  i++){
    map_20.put(arr_20[i], arr_20[i]);
  }
  EXPECT_EQ(map_20.Size(), 3);
  
  // bool type
  mymap<bool, bool> map_24;
  bool arr_24[] = {true, false};
  for(int i=0; i < 2;  i++){
    map_24.put(arr_24[i], arr_24[i]);
  }
  EXPECT_EQ(map_24.Size(), 2);
  
  // double type
  mymap<double, double> map_6;
  double arr_6[] = {2.00, 1.00, 3.00};
  for(int i=0; i < 3;  i++){
    map_6.put(arr_6[i], arr_6[i]);
  }
  EXPECT_EQ(map_6.Size(), 3);
}

// Test for contains
TEST(mymap, three){
	// testing for int
	mymap<int, int> map_1;
	int arr[] = {2, 1, 3};
  for(int i=0; i < 3;  i++){
    map_1.put(arr[i], arr[i]);
	}
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_1.contains(arr[i]));
	}
	
	mymap<int, int> map_1_1;
	for(int i = 0; i < 4; i++){
		EXPECT_FALSE(map_1_1.contains(arr[i]));
	}
	
	// char type
  mymap<char, char> map_13;
  char arr_13[] = {'a', 'b', 'c'};
  for(int i=0; i < 3;  i++){
    map_13.put(arr_13[i], arr_13[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_13.contains(arr_13[i]));
	}
	
	mymap<char, char> map_13_1;
	for(int i = 0; i < 4; i++){
		EXPECT_FALSE(map_13_1.contains(arr[i]));
	}
	
	// string type
  mymap<string, string> map_20;
  string arr_20[] = {"first", "second", "third"};
  for(int i=0; i < 3;  i++){
    map_20.put(arr_20[i], arr_20[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_20.contains(arr_20[i]));
	}
	
	// bool type
  mymap<bool, bool> map_24;
  bool arr_24[] = {true, false};
  for(int i=0; i < 2;  i++){
    map_24.put(arr_24[i], arr_24[i]);
  }
	for(int i = 0; i < 2; i++){
		EXPECT_TRUE(map_24.contains(arr_24[i]));
	}
	
	mymap<bool, bool> map_24_1;
	for(int i = 0; i < 4; i++){
		EXPECT_FALSE(map_24_1.contains(arr[i]));
	}
	
	// double type
  mymap<double, double> map_6;
  double arr_6[] = {2.00, 1.00, 3.00};
  for(int i=0; i < 3;  i++){
    map_6.put(arr_6[i], arr_6[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_6.contains(arr_6[i]));
	}
	
	mymap<double, double> map_6_1;
	for(int i = 0; i < 4; i++){
		EXPECT_FALSE(map_6_1.contains(arr[i]));
	}
}

// Test for get
TEST(mymap, four){
	
	// int type
	mymap<int, int> map_1;
	int arr[] = {2, 1, 3};
  for(int i=0; i < 3;  i++){
    map_1.put(arr[i], arr[i]);
	}
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_1.contains(arr[i]));
	}
	for(int i =0; i <3; i++){
		EXPECT_EQ(map_1.get(arr[i]), arr[i]);
		EXPECT_EQ(map_1.Size(), 3);
	}
	
	// char type
  mymap<char, char> map_13;
  char arr_13[] = {'a', 'b', 'c'};
  for(int i=0; i < 3;  i++){
    map_13.put(arr_13[i], arr_13[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_13.contains(arr_13[i]));
	}
	for(int i =0; i <3; i++){
		EXPECT_EQ(map_13.get(arr_13[i]), arr_13[i]);
		EXPECT_EQ(map_13.Size(), 3);
	}
	
	// string type
  mymap<string, string> map_20;
  string arr_20[] = {"first", "second", "third"};
  for(int i=0; i < 3;  i++){
    map_20.put(arr_20[i], arr_20[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_20.contains(arr_20[i]));
	}
	for(int i =0; i <3; i++){
		EXPECT_EQ(map_20.get(arr_20[i]), arr_20[i]);
		EXPECT_EQ(map_20.Size(), 3);
	}
	
	// bool type
  mymap<bool, bool> map_24;
  bool arr_24[] = {true, false};
  for(int i=0; i < 2;  i++){
    map_24.put(arr_24[i], arr_24[i]);
  }
	for(int i = 0; i < 2; i++){
		EXPECT_TRUE(map_24.contains(arr_24[i]));
	}
	for(int i =0; i <2; i++){
		EXPECT_EQ(map_24.get(arr_24[i]), arr_24[i]);
		EXPECT_EQ(map_24.Size(), 2);
	}
	
	// double type
  mymap<double, double> map_6;
  double arr_6[] = {2.00, 1.00, 3.00};
  for(int i=0; i < 3;  i++){
    map_6.put(arr_6[i], arr_6[i]);
  }
	for(int i = 0; i < 3; i++){
		EXPECT_TRUE(map_6.contains(arr_6[i]));
	}
	for(int i =0; i <3; i++){
		EXPECT_EQ(map_6.get(arr_6[i]), arr_6[i]);
		EXPECT_EQ(map_6.Size(), 3);
	}
}

// Test for toString
TEST(mymap, stress) {
   // from project pdf:
   mymap<int, int> test;
   map<int, int> correct;
   int seed = 1000000;
   for(int i = 0; i < 100;
   i++) {
	// randomize key and val
	int k = randomInteger(0,seed);
	int v = randomInteger(0,seed);
	test.put(k, v);
	correct[k] = v;
  }
  EXPECT_EQ(test.Size(),correct.size());
}

TEST(mymap, five){
  
  mymap<int, int> map_0;
  map_0.put(1, 2);
  map_0.put(3, 4);
  map_0.put(5, 6);
  map_0.put(7, 8);
  map_0.put(9, 10);
  
  string map = map_0.toString();
  string sol_0 = "key: 1 value: 2\nkey: 3 value: 4\nkey: 5 value: 6\nkey: 7 value: 8\nkey: 9 value: 10\n";
  ASSERT_EQ(sol_0, map_0.toString());
  
  // int type
  mymap<int, int> map_1;
  map_1.put(13, 56);
  map_1.put(9, 87);
  map_1.put(28, 12);
  map_1.put(11, 10);
  map_1.put(8, 7);
  map_1.put(54, 11);
  map_1.put(99, 15);
  
  string map_1_1 = map_1.toString();
  string sol = "key: 8 value: 7\nkey: 9 value: 87\nkey: 11 value: 10\nkey: 13 value: 56\nkey: 28 value: 12\nkey: 54 value: 11\nkey: 99 value: 15\n";
  ASSERT_EQ(sol, map_1.toString());
  
  mymap<int, double> map_2;
  map_2.put(13, 56.00);
  map_2.put(9, 87.00);
  map_2.put(28, 12.00);
  map_2.put(11, 10.00);
  map_2.put(8, 7.00);
  map_2.put(54, 11.00);
  map_2.put(99, 15.00);
  
  string map_1_2 = map_2.toString();
  string sol_2 = "key: 8 value: 7\nkey: 9 value: 87\nkey: 11 value: 10\nkey: 13 value: 56\nkey: 28 value: 12\nkey: 54 value: 11\nkey: 99 value: 15\n";
  ASSERT_EQ(sol_2, map_2.toString());
  
  // char type
  mymap<char, char> map_13;  
  map_13.put('a', 'c');
  map_13.put('l', 'b');
  map_13.put('d', 'h');
  map_13.put('w', 'b');
  map_13.put('a', 'd');
  map_13.put('r', 'o');
  map_13.put('k', 'n');
  
  string map_13_1 = map_13.toString();
  string sol_13 = "key: a value: d\nkey: d value: h\nkey: k value: n\nkey: l value: b\nkey: r value: o\nkey: w value: b\n";
  ASSERT_EQ(sol_13, map_13.toString());
  
  // string type
  mymap<string, string> map_20;
  map_20.put("antohny", "Carmelo");
  map_20.put("lebron", "james");
  map_20.put("dwight", "howard");
  map_20.put("wwest", "brook");
  map_20.put("anthony", "davis");
  map_20.put("rajon", "rondo");
  
  string map_20_1 = map_20.toString();
  string sol_20 = "key: anthony value: davis\nkey: antohny value: Carmelo\nkey: dwight value: howard\nkey: lebron value: james\nkey: rajon value: rondo\nkey: wwest value: brook\n";
  ASSERT_EQ(sol_20, map_20.toString());
   
}

// this is testing for the operator

TEST(mymap, six){
  
  // testing for int and int
  mymap<int, int> map_1;
  int arr[] = {2, 1, 3};
  for(int i=0; i < 3;  i++){
    map_1.put(arr[i], arr[i]);
  }
  for (int i = 0; i <3; i++){
     EXPECT_EQ(map_1[arr[i]], arr[i]);
      EXPECT_EQ(map_1.Size(), 3);
  }
  
  ASSERT_EQ(map_1[9281], 0);
  ASSERT_EQ(map_1.get(9281), 0);

  // testing for char char 
  mymap<char, char> map_13;
  char arr_13[] = {'a', 'b', 'c'};
  for(int i=0; i < 3;  i++){
    map_13.put(arr_13[i], arr_13[i]);
  }
  for (int i = 0; i <3; i++){
    EXPECT_EQ(map_13[arr_13[i]], arr_13[i]);
    EXPECT_EQ(map_13.Size(), 3);
  }
}

// test for mildstone 3
TEST(mymap, seven){
  mymap<int, int> map_1;
  int arr[] = {2, 1, 3};
  int order[] = {1, 2, 3};
  for( int i = 0; i <3; i++){
    map_1.put(arr[i], arr[i]);
  }
  
  int i =0;
  for( auto key : map_1){
    EXPECT_EQ(order[i++], key);
  } 
}

// test for mildstone 4
TEST(mymap, eight){
  // test for int and int
  mymap<int, int> map_1;
  map_1.put(13, 56);
  map_1.put(9, 87);
  map_1.put(28, 12);
  map_1.put(11, 10);
  map_1.put(8, 7);
  map_1.put(54, 11);
  map_1.put(99, 15);
  map_1.clear();
  EXPECT_EQ(map_1.Size(), 0);
}

TEST(mymap, nine){
  mymap<int, int> map_1;
  map_1.put(13, 56);
  map_1.put(9, 87);
  map_1.put(28, 12);
  map_1.put(11, 10);
  map_1.put(8, 7);
  map_1.put(54, 11);
  map_1.put(99, 15);
  mymap<int, int> map_1_copy;
  map_1_copy = map_1;
}

// this is test for toVector
TEST(mymap, ten){
  
  mymap<int, int> map_1;
  map_1.put(13, 56);
  map_1.put(9, 87);
  map_1.put(28, 12);
  mymap<int, int> map_1_copy;
  map_1_copy = map_1;
  
  vector<pair<int, int>> solution;
  pair<int, int> s_1(9, 87);
  solution.push_back(s_1);
  pair<int, int> s_2(13, 56);  
  solution.push_back(s_2);
  pair<int, int> s_3(28, 12);  
  solution.push_back(s_3);
  EXPECT_EQ(solution,  map_1_copy.toVector());
}

TEST(mymap, eleven){
  
  mymap<int, int> map_0;
  map_0.put(1, 2);
  map_0.put(3, 4);
  map_0.put(5, 6);
  map_0.put(7, 8);
  map_0.put(9, 10);
  
  string sol_0 =  "key: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\nkey: 5, nL: 0, nR: 0\nkey: 7, nL: 0, nR: 0\nkey: 9, nL: 0, nR: 0\n";
  ASSERT_EQ(sol_0, map_0.checkBalance());
  
  // int type
  mymap<int, int> map_1;
  map_1.put(13, 56);
  map_1.put(9, 87);
  map_1.put(28, 12);
  map_1.put(11, 10);
  map_1.put(8, 7);
  map_1.put(54, 11);
  map_1.put(99, 15);
  
  string sol = "key: 13, nL: 0, nR: 0\nkey: 9, nL: 0, nR: 0\nkey: 8, nL: 0, nR: 0\nkey: 11, nL: 0, nR: 0\nkey: 28, nL: 0, nR: 0\nkey: 54, nL: 0, nR: 0\nkey: 99, nL: 0, nR: 0\n";
  ASSERT_EQ(sol, map_1.checkBalance());
  
  mymap<int, double> map_2;
  map_2.put(13, 56.00);
  map_2.put(9, 87.00);
  map_2.put(28, 12.00);
  map_2.put(11, 10.00);
  map_2.put(8, 7.00);
  map_2.put(54, 11.00);
  map_2.put(99, 15.00);
  
  string sol_2 = "key: 13, nL: 0, nR: 0\nkey: 9, nL: 0, nR: 0\nkey: 8, nL: 0, nR: 0\nkey: 11, nL: 0, nR: 0\nkey: 28, nL: 0, nR: 0\nkey: 54, nL: 0, nR: 0\nkey: 99, nL: 0, nR: 0\n";
  ASSERT_EQ(sol_2, map_2.checkBalance());
  
  // char type
  mymap<char, char> map_13;  
  map_13.put('a', 'c');
  map_13.put('l', 'b');
  map_13.put('d', 'h');
  map_13.put('w', 'b');
  map_13.put('a', 'd');
  map_13.put('r', 'o');
  map_13.put('k', 'n');
  
  string sol_13 = "key: a, nL: 0, nR: 0\nkey: l, nL: 0, nR: 0\nkey: d, nL: 0, nR: 0\nkey: k, nL: 0, nR: 0\nkey: w, nL: 0, nR: 0\nkey: r, nL: 0, nR: 0\n";
  ASSERT_EQ(sol_13, map_13.checkBalance());
  
  // string type
  mymap<string, string> map_20;
  map_20.put("antohny", "Carmelo");
  map_20.put("lebron", "james");
  map_20.put("dwight", "howard");
  map_20.put("wwest", "brook");
  map_20.put("anthony", "davis");
  map_20.put("rajon", "rondo");
  
  string sol_20 = "key: antohny, nL: 0, nR: 0\nkey: anthony, nL: 0, nR: 0\nkey: lebron, nL: 0, nR: 0\nkey: dwight, nL: 0, nR: 0\nkey: wwest, nL: 0, nR: 0\nkey: rajon, nL: 0, nR: 0\n";
  ASSERT_EQ(sol_20, map_20.checkBalance());
}

TEST(mymap, stress_1) {
   // from project pdf:
   mymap<int, int> test;
   map<int, int> correct;
   int seed = 1000000;
   for(int i = 0; i < 10000;
   i++) {
	// randomize key and val
	int k = randomInteger(0,seed);
	int v = randomInteger(0,seed);
	test.put(k, v);
	correct[k] = v;
  }
  EXPECT_EQ(test.Size(),correct.size());
}
