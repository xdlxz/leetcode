349，两个数组的交集

/*
Given two arrays, write a function to compute their intersection.
 
Example 1:
 
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:
 
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:
 
Each element in the result must be unique.
The result can be in any order.
 
sort arry;  binary find;
用set去重
*/
 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        quik_sort(nums1,0,nums1.size()-1);
        for(int i=0;i<nums2.size();i++)
        {
            if(binary_find(nums1,nums2[i])){
                s.insert(nums2[i]);
            }
        }
        return vector<int>(s.begin(),s.end());
    }
 
    //二分查找
    bool binary_find(vector<int> vec,int target)
    {
        if(vec.size() == 0){
            return false;
        }
        int left = 0;
        int right = vec.size()-1;
 
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(vec[mid] == target){
                return true;
            }
 
            if(vec[mid] < target)
            {
               left = mid+1; 
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
 
    void quik_sort(vector<int> &arr, int i, int j)
    {
        if(i>=j){
            return;
        }
 
        int x = arr[i];
        int l=i,r=j;
        while(l<r)
        {
            //从右往左，找一个<x的数
            while(l<r && arr[r] >= x){
                r--;
            }
            if(l<r)
            {
                arr[l] = arr[r];
                l++;
            }
            //从左往右，找一个>=x的
            while(l<r && arr[l] < x)
            {
                l++;
            }
            if(l<r)
            {
                arr[r] = arr[l];
                r--;
            }
        }//end while
 
        arr[l] = x;
        quik_sort(arr,i,l-1);
        quik_sort(arr,l+1,j);
    }
 
    void print(vector<int> vec)
    {
        for(int i=0; i<vec.size();i++){
            cout << vec[i] << endl;
        }
    }
 
 
};
 
 
//error
 
//二分查找
    bool binary_find(vector<int> vec,int target)
    {
        if(vec.size() == 0){
            return false;
        }
        int left = 0;
        int right = vec.size()-1;
 
        while(left <= right)   //这里引入等号的话，left=mid+1 或者 right = mid-1;
        {
 
            int mid = left + (right-left)/2;
            if(vec[mid] == target){
                return true;
            }
            if(vec[mid] < target)
            {
               left = mid+1; 
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
};
