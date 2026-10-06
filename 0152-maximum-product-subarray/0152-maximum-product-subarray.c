int maxProduct(int* nums, int numsSize) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int x = nums[i];

        if (x < 0) {
            int temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }

        maxProd = x > maxProd * x ? x : maxProd * x;
        minProd = x < minProd * x ? x : minProd * x;

        ans = ans > maxProd ? ans : maxProd;
    }

    return ans;
}