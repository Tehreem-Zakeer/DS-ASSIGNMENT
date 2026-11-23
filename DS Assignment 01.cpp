#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <chrono>
#include <cstdlib> 
#include <algorithm>

// Part 2 (a) : Insertion Sort
template <typename T>
void insertionSort(std::vector<T>& v)
{
	int n = v.size();
	for (int i = 1; i < n; ++i) 
	{
		T key = v[i]; 
		int j = i - 1;
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

// Part 2 (b): 
// Reheap Down
template <typename T>
void ReheapDown(std::vector <T>& v, int first, int last)
{
	int l, r, m;
	l = first * 2 + 1;
	r = first * 2 + 2;
	m = l;
	while (l <= last)
	{
		if (r <= last)
		{
			if (v[r] > v[l])
			{
				m = r;
			}
		}
		if (v[first] < v[m])
		{
			std::swap(v[first], v[m]);
			first = m;
			l = first * 2 + 1;
			r = first * 2 + 2;
			m = l;
		}
		else
			break;
	}
}

// Heap Sorting
template <typename T>
void heapsort(std::vector <T>& v)
{
	int n = v.size();

	for (int i = n / 2 - 1; i >= 0; --i)
	{
		ReheapDown(v, i, n - 1);
	}

	for (int i = n - 1; i > 0; --i)
	{
		std::swap(v[0], v[i]);
		ReheapDown(v, 0, i - 1);
	}
}

int main()
{
	std::cout << "IMPLEMENTATION FOR VECTORS" << std::endl;
	std::cout << std::endl<<std::endl;
	// Vector Part 1 (a)
	std::vector<int> vec_A;
	auto start_A = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		vec_A.push_back(i);
	}
	auto end_A = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_vec_A_asc = end_A - start_A;
	std::cout <<"Vector A Ascending Time Taken: "<< t_vec_A_asc.count() <<"ms"<< std::endl;
	std::cout << std::endl;

	// Vector Part 1 (b)
	std::vector<int> vec_B;
	auto start_B = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1; --i)
	{
		vec_B.push_back(i);
	}
	auto end_B = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli>t_vec_B_des = end_B - start_B;
	std::cout << "Vector B Descending Time Taken: " << t_vec_B_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Vector Part 1 (c)
	std::vector<int>vec_C;
	srand(50);
	auto start_C = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		vec_C.push_back(rand() % 100000 + 1);
	}
	auto end_C = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_vec_C_rand = end_C - start_C;
	std::cout << "Vector C Random Time Taken: " << t_vec_C_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Vector Part 1 (d)
	auto start_sA = std::chrono::high_resolution_clock::now();
	std::sort(vec_A.begin(), vec_A.end());
	auto end_sA = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_A = end_sA - start_sA;
	std::cout << "Vector A Sorting Time Taken: " << t_sort_A.count() << "ms" << std::endl;
	std::cout << std::endl;
	
	auto start_sB = std::chrono::high_resolution_clock::now();
	std::sort(vec_B.begin(), vec_B.end());
	auto end_sB = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_B = end_sB - start_sB;
	std::cout << "Vector B Sorting Time Taken: " << t_sort_B.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_sC = std::chrono::high_resolution_clock::now();
	std::sort(vec_C.begin(), vec_C.end());
	auto end_sC = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_C = end_sC - start_sC;
	std::cout << "Vector C Sorting Time Taken: " << t_sort_C.count() << "ms" << std::endl;
	std::cout << std::endl;
	
	// Vector Part 1 (e)
	std::vector<int> vec_E;
	auto start_E = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		vec_E.push_back(i);
	}
	auto end_E = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_vec_E_asc = end_E - start_E;
	std::cout << "Vector E Ascending Time Taken: " << t_vec_E_asc.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Vector Part 1 (f)
	std::vector<int> vec_F;
	auto start_F = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1; --i)
	{
		vec_F.push_back(i);
	}
	auto end_F = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli>t_vec_F_des = end_F - start_F;
	std::cout << "Vector F Descending Time Taken: " << t_vec_F_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Vector Part 1 (g)
	std::vector<int>vec_G;
	srand(50);
	auto start_G = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		vec_G.push_back(rand() % 100000 + 1);
	}
	auto end_G = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_vec_G_rand = end_G - start_G;
	std::cout << "Vector G Random Time Taken: " << t_vec_G_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Vector Part 1 (h)
	auto start_del_Odd_VE = std::chrono::high_resolution_clock::now();
	std::erase_if(vec_E, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_VE = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_VE = end_del_Odd_VE - start_del_Odd_VE;
	std::cout << "Del Odd Vector E Time Taken: " << t_del_Odd_VE.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_VF = std::chrono::high_resolution_clock::now();
	std::erase_if(vec_F, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_VF = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_VF = end_del_Odd_VF - start_del_Odd_VF;
	std::cout << "Del Odd Vector F Time Taken: " << t_del_Odd_VF.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_VG = std::chrono::high_resolution_clock::now();
	std::erase_if(vec_G, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_VG = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_VG = end_del_Odd_VG - start_del_Odd_VG;
	std::cout << "Del Odd Vector G Time Taken: " << t_del_Odd_VG.count() << "ms" << std::endl;
	std::cout << std::endl << std::endl;;

	std::cout << "IMPLEMENTATION FOR FORWARD LIST" << std::endl;
	std::cout << std::endl<<std::endl;
	// Forward List Part 1 (a)
	std::forward_list<int> F_A;
	auto it_A = F_A.before_begin();
	auto start_F_A = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000;++i)
	{
		it_A = F_A.insert_after(it_A, i);
	}
	auto end_F_A = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_A_asc = end_F_A - start_F_A;
	std::cout << "Forward List A Ascending Time Taken: " << t_F_A_asc.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (b)
	std::forward_list<int> F_B;
	auto it_B = F_B.before_begin();
	auto start_F_B = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1;--i)
	{
		it_B = F_B.insert_after(it_B, i);
	}
	auto end_F_B = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_B_des = end_F_B - start_F_B;
	std::cout << "Forward List B Descending Time Taken: " << t_F_B_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (c)
	std::forward_list<int> F_C;
	srand(50);
	auto it_C = F_C.before_begin();
	auto start_F_C = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000;++i)
	{
		it_C = F_C.insert_after( it_C, rand()% 100000 +1 );
	}
	auto end_F_C = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_C_rand = end_F_C - start_F_C;
	std::cout << "Forward List C Random Time Taken: " << t_F_C_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (d)
	auto start_F_s_A = std::chrono::high_resolution_clock::now();
	F_A.sort();
	auto end_F_s_A = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_A_sort = end_F_s_A - start_F_s_A;
	std::cout << "Forward List A Sorting Time Taken: " << t_F_A_sort.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_F_s_B = std::chrono::high_resolution_clock::now();
	F_B.sort();
	auto end_F_s_B = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_B_sort = end_F_s_B - start_F_s_B;
	std::cout << "Forward List B Sorting Time Taken: " << t_F_B_sort.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_F_s_C = std::chrono::high_resolution_clock::now();
	F_C.sort();
	auto end_F_s_C = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_C_sort = end_F_s_C - start_F_s_C;
	std::cout << "Forward List C Sorting Time Taken: " << t_F_C_sort.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (e)
	std::forward_list<int> F_E;
	auto it_E = F_E.before_begin();
	auto start_F_E = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000;++i)
	{
		it_E = F_E.insert_after(it_E, i);
	}
	auto end_F_E = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_E_asc = end_F_E - start_F_E;
	std::cout << "Forward List E Ascending Time Taken: " << t_F_E_asc.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (f)
	std::forward_list<int> F_F;
	auto it_F = F_F.before_begin();
	auto start_F_F = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1;--i)
	{
		it_F = F_F.insert_after(it_F, i);
	}
	auto end_F_F = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_F_des = end_F_F - start_F_F;
	std::cout << "Forward List F Descending Time Taken: " << t_F_F_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (g)
	std::forward_list<int> F_G;
	srand(50);
	auto it_G = F_G.before_begin();
	auto start_F_G = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000;++i)
	{
		it_G = F_G.insert_after(it_G, rand() % 100000 + 1);
	}
	auto end_F_G = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_F_G_rand = end_F_G - start_F_G;
	std::cout << "Forward List G Random Time Taken: " << t_F_G_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// Forward List Part 1 (h)
	auto start_del_Odd_FE = std::chrono::high_resolution_clock::now();
	std::erase_if(F_E, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_FE = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_FE = end_del_Odd_FE - start_del_Odd_FE;
	std::cout << "Del Odd Forward List E Time Taken: " << t_del_Odd_FE.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_FF = std::chrono::high_resolution_clock::now();
	std::erase_if(F_F, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_FF = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_FF = end_del_Odd_FF - start_del_Odd_FF;
	std::cout << "Del Odd Forward List F Time Taken: " << t_del_Odd_FF.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_FG = std::chrono::high_resolution_clock::now();
	std::erase_if(F_G, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_FG = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_FG = end_del_Odd_FG - start_del_Odd_FG;
	std::cout << "Del Odd Forward List G Time Taken: " << t_del_Odd_FG.count() << "ms" << std::endl;
	std::cout << std::endl<<std::endl;

	std::cout << "IMPLEMENTATION FOR LIST" << std::endl;
	std::cout << std::endl<<std::endl;
	// List Part 1 (a)
	std::list<int> L_A;
	auto start_LA = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		L_A.push_back(i);
	}
	auto end_LA = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_L_A_asc = end_LA - start_LA;
	std::cout << "List A Ascending Time Taken: " << t_L_A_asc.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (b)
	std::list<int> L_B;
	auto start_LB = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1; --i)
	{
		L_B.push_back(i);
	}
	auto end_LB = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli>t_L_B_des = end_LB - start_LB;
	std::cout << "List B Descending Time Taken: " << t_L_B_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (c)
	std::list<int>L_C;
	srand(50);
	auto start_LC = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		L_C.push_back(rand() % 100000 + 1);
	}
	auto end_LC = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_L_C_rand = end_LC - start_LC;
	std::cout << "List C Random Time Taken: " << t_L_C_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (d)
	auto start_sLA = std::chrono::high_resolution_clock::now();
	L_A.sort();
	auto end_sLA = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_LA = end_sLA - start_sLA;
	std::cout << "List A Sorting Time Taken: " << t_sort_LA.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_sLB = std::chrono::high_resolution_clock::now();
	L_B.sort();
	auto end_sLB = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_LB = end_sLB - start_sLB;
	std::cout << "List B Sorting Time Taken: " << t_sort_LB.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_sLC = std::chrono::high_resolution_clock::now();
	L_C.sort();
	auto end_sLC = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_sort_LC = end_sLC - start_sLC;
	std::cout << "List C Sorting Time Taken: " << t_sort_LC.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (e)
	std::list<int> L_E;
	auto start_LE = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		L_E.push_back(i);
	}
	auto end_LE = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_L_E_asc = end_LE - start_LE;
	std::cout << "List E Ascending Time Taken: " << t_L_E_asc.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (f)
	std::list<int> L_F;
	auto start_LF = std::chrono::high_resolution_clock::now();
	for (int i = 100000; i >= 1; --i)
	{
		L_F.push_back(i);
	}
	auto end_LF = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli>t_L_F_des = end_LF - start_LF;
	std::cout << "List F Descending Time Taken: " << t_L_F_des.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (g)
	std::list<int>L_G;
	srand(50);
	auto start_LG = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 100000; ++i)
	{
		L_G.push_back(rand() % 100000 + 1);
	}
	auto end_LG = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_L_G_rand = end_LG - start_LG;
	std::cout << "List G Random Time Taken: " << t_L_G_rand.count() << "ms" << std::endl;
	std::cout << std::endl;

	// List Part 1 (h)
	auto start_del_Odd_LE = std::chrono::high_resolution_clock::now();
	std::erase_if(L_E, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_LE = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_LE = end_del_Odd_LE - start_del_Odd_LE;
	std::cout << "Del Odd List E Time Taken: " << t_del_Odd_LE.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_LF = std::chrono::high_resolution_clock::now();
	std::erase_if(L_F, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_LF = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_LF = end_del_Odd_LF - start_del_Odd_LF;
	std::cout << "Del Odd List F Time Taken: " << t_del_Odd_LF.count() << "ms" << std::endl;
	std::cout << std::endl;

	auto start_del_Odd_LG = std::chrono::high_resolution_clock::now();
	std::erase_if(L_G, [](int x) -> bool {return x % 2 == 1;});
	auto end_del_Odd_LG = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_del_Odd_LG = end_del_Odd_LG - start_del_Odd_LG;
	std::cout << "Del Odd List G Time Taken: " << t_del_Odd_LG.count() << "ms" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "HEAP SORT FOR VECTORS" << std::endl;
	std::cout << std::endl << std::endl;
	// Part 2 (c)
	std::vector<int> v_a;
	for (int i = 1; i <= 100000; ++i)
	{
		v_a.push_back(i);
	}
	auto start_hs_a = std::chrono::high_resolution_clock::now();
	heapsort(v_a);
	auto end_hs_a = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_hs_a = end_hs_a - start_hs_a;
	std::cout << "Heap Sort Vector A Time Taken: " << t_hs_a.count() << "ms" << std::endl;
	std::cout << std::endl;

	std::vector<int> v_b;
	for (int i = 100000; i >= 1; --i)
	{
		v_b.push_back(i);
	}
	auto start_hs_b = std::chrono::high_resolution_clock::now();
	heapsort(v_b);
	auto end_hs_b = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_hs_b = end_hs_b - start_hs_b;
	std::cout << "Heap Sort Vector B Time Taken: " << t_hs_b.count() << "ms" << std::endl;
	std::cout << std::endl;

	std::vector<int> v_c;
	srand(50);
	for (int i = 1; i <= 100000; ++i)
	{
		v_c.push_back(rand() % 100000 +1);

	}
	auto start_hs_c = std::chrono::high_resolution_clock::now();
	heapsort(v_c);
	auto end_hs_c = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_hs_c = end_hs_c - start_hs_c;
	std::cout << "Heap Sort Vector C Time Taken: " << t_hs_c.count() << "ms" << std::endl;
	std::cout << std::endl<<std::endl;

	std::cout << "INSERTION SORT FOR VECTORS" << std::endl;
	std::cout << std::endl<<std::endl;

	// Part 2 (d)
	std::vector<int> v_e;
	for (int i = 1; i <= 100000; ++i)
	{
		v_e.push_back(i);
	}
	auto start_is_e = std::chrono::high_resolution_clock::now();
	insertionSort(v_e);
	auto end_is_e = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_is_e = end_is_e - start_is_e;
	std::cout << "Insertion Sort Vector E Time Taken: " << t_is_e.count() << "ms" << std::endl;
	std::cout << std::endl;

	std::vector<int> v_f;
	for (int i = 100000; i >= 1; --i)
	{
		v_f.push_back(i);
	}
	auto start_is_f = std::chrono::high_resolution_clock::now();
	insertionSort(v_f);
	auto end_is_f = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_is_f = end_is_f - start_is_f;
	std::cout << "Insertion Sort Vector F Time Taken: " << t_is_f.count() << "ms" << std::endl;
	std::cout << std::endl;

	std::vector<int> v_g;
	srand(50);
	for (int i = 1; i <= 100000; ++i)
	{
		v_g.push_back(rand() % 100000 + 1);

	}
	auto start_is_g = std::chrono::high_resolution_clock::now();
	insertionSort(v_g);
	auto end_is_g = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> t_is_g = end_is_g - start_is_g;
	std::cout << "Insertion Sort Vector G Time Taken: " << t_is_g.count() << "ms" << std::endl;
	std::cout << std::endl;

	return 0;
}

