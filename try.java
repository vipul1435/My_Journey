class Knapsack {
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    static int knapSack_function(int capacity, int weight[], int value[], int n) {
        int i, w;
        int DP[][] = new int[n + 1][capacity + 1];
        for (i = 0; i <= n; i++) {
            for (w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0)
                    DP[i][w] = 0;
                else if (weight[i - 1] <= w)
                    DP[i][w] = max(value[i - 1] + DP[i - 1][w - weight[i - 1]], DP[i - 1][w]);
                else
                    DP[i][w] = DP[i - 1][w];
            }
        }
        return DP[n][capacity];
    }

    public static void main(String args[]) {
        int value[] = new int[] { 30, 25, 30 };
        int weight[] = new int[] { 4, 3, 2 };
        int capacity = 9;
        int n = value.length;
        System.out.println(knapSack_function(capacity, weight, value, n));
    }
}