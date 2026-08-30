class Solution {

    public int minimumDeletions(int[] arr) {

        int n = arr.length;

        if (n == 1) return 1;

        int min = arr[0];
        int max = arr[0];

        int pos1 = 0;
        int pos2 = 0;

        // minimum aur maximum ki position find karo
        for (int i = 1; i < n; i++) {

            if (min > arr[i]) {
                min = arr[i];
                pos1 = i;
            }

            if (max < arr[i]) {
                max = arr[i];
                pos2 = i;
            }
        }

        // dono left se delete karne par
        int left;

        if (pos1 > pos2) {
            left = pos1 + 1;
        } else {
            left = pos2 + 1;
        }

        // dono right se delete karne par
        int right;

        if (pos1 < pos2) {
            right = n - pos1;
        } else {
            right = n - pos2;
        }

        // ek left se aur ek right se
        int both;

        if (pos1 < pos2) {
            both = pos1 + 1 + n - pos2;
        } else {
            both = pos2 + 1 + n - pos1;
        }

        // minimum option return karo
        if (left < right && left < both) {
            return left;
        }
        else if (right < both) {
            return right;
        }
        else {
            return both;
        }
    }
}