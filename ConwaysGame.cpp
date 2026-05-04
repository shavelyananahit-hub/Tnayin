const int max = 1000;

int next(int X[], int Y[], int n) {
    int x1[max], y1[max], n1 = 0;

    for(int i = 0; i < n; i++) {

        for(int x2 = -1; x2 <= 1; x2++) {
            for(int y2 = -1; y2 <= 1; y2++) {

                int x = X[i] + x2;
                int y = Y[i] + y2;

                int count = 0;

                for(int k = 0; k < n; k++)
                    for(int x2 = -1; x2 <= 1; x2++)
                        for(int y2 = -1; y2 <= 1; y2++)
                            if(!(x2 == 0 && y2 == 0))
                                if(X[k] == x + x2 && Y[k] == y + y2)
                                    count++;

                int exists = 0;
                for(int k = 0; k < n; k++)
                    if(X[k] == x && Y[k] == y)
                        exists = 1;

                if(count == 3 || (exists && count == 2)) {
                    x1[n1] = x;
                    y1[n1] = y;
                    n1++;
                }
            }
        }
    }

    for(int i = 0; i < n1; i++) {
        X[i] = x1[i];
        Y[i] = y1[i];
    }

    return n1;
}