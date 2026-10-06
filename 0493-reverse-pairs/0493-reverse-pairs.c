void merge(int *nums, int *temp, int left, int mid, int right, int *count) {
    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j])
            j++;
        *count += j - (mid + 1);
    }

    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
        temp[k++] = nums[i++];

    while (j <= right)
        temp[k++] = nums[j++];

    for (i = left; i <= right; i++)
        nums[i] = temp[i];
}

void mergeSort(int *nums, int *temp, int left, int right, int *count) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, temp, left, mid, count);
    mergeSort(nums, temp, mid + 1, right, count);
    merge(nums, temp, left, mid, right, count);
}

int reversePairs(int* nums, int numsSize) {
    if (numsSize < 2)
        return 0;

    int *temp = malloc(numsSize * sizeof(int));
    int count = 0;

    mergeSort(nums, temp, 0, numsSize - 1, &count);

    free(temp);
    return count;
}