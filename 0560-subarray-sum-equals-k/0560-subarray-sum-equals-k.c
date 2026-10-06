

int subarraySum(int* nums, int numsSize, int k) {
    int size = 100003;
    int *key = calloc(size, sizeof(int));
    int *value = calloc(size, sizeof(int));
    char *used = calloc(size, sizeof(char));

    int sum = 0, ans = 0;

    int h = 0;
    used[h] = 1;
    key[h] = 0;
    value[h] = 1;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        int target = sum - k;
        h = ((target % size) + size) % size;

        while (used[h] && key[h] != target)
            h = (h + 1) % size;

        if (used[h])
            ans += value[h];

        h = ((sum % size) + size) % size;

        while (used[h] && key[h] != sum)
            h = (h + 1) % size;

        if (used[h])
            value[h]++;
        else {
            used[h] = 1;
            key[h] = sum;
            value[h] = 1;
        }
    }

    free(key);
    free(value);
    free(used);

    return ans;
}