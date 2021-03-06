//
//  main.cpp
//  48. Rotate Image
//
//  Created by chenyufeng on 10/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    long n = matrix.size();
    // 控制共有几个环
    for(long layer = 0; layer < n / 2; layer++)
    {
        long begin = layer; // 每一圈开始位置
        long end = n - 1 - layer; // 每一圈结束位置
        //旋转第layer层
        for(long i = begin; i < end; i++)
        {
            long offset = i - begin;
            //保存上面的值
            int top = matrix[begin][i];
            //左边转到上面
            matrix[begin][i] = matrix[end-offset][begin];
            //下面转到左边
            matrix[end-offset][begin] = matrix[end][end-offset];
            //右边转到下面
            matrix[end][end-offset] = matrix[i][end];
            //上面转到右边
            matrix[i][end] = top;
        }
    }
}

int main(int argc, const char * argv[])
{

     vector<vector<int>> matrix;
     int arr1[] = {1,2,3,4};
     int arr2[] = {5,6,7,8};
     int arr3[] = {9,10,11,12};
     int arr4[] = {13,14,15,16};
     vector<int> mat1(arr1,arr1+sizeof(arr1)/sizeof(int));
     vector<int> mat2(arr2,arr2+sizeof(arr2)/sizeof(int));
     vector<int> mat3(arr3,arr3+sizeof(arr3)/sizeof(int));
     vector<int> mat4(arr4,arr4+sizeof(arr4)/sizeof(int));

     matrix.push_back(mat1);
     matrix.push_back(mat2);
     matrix.push_back(mat3);
     matrix.push_back(mat4);

     rotate(matrix);

    for (long i = 0; i < matrix.size(); i++)
    {
        for (long j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
