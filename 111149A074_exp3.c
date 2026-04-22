#include <stdio.hgt>
#include <stdlib.h>
#define MAX 100
// Function to print bins
void printBins(int bin[], int binsUsed) {
printf(&quot;Total bins used: %d\n&quot;, binsUsed);
}

void firstFit(int weight[], int n, int capacity) {
int bin_rem[MAX];
int binsUsed = 0;
for (int i = 0; i &lt; n; i++) {
int placed = 0;
for (int j = 0; j &lt; binsUsed; j++) {
if (bin_rem[j] &gt;= weight[i]) {
bin_rem[j] -= weight[i];
placed = 1;
break;
}
}
if (!placed) {
bin_rem[binsUsed] = capacity - weight[i];
binsUsed++;
}
}

printf(&quot;\nFirst Fit:\n&quot;);
printBins(bin_rem, binsUsed);
}

// Comparator for sorting in descending order
int compare(const void *a, const void *b) {
return (*(int*)b - *(int*)a);
}
void firstFitDecreasing(int weight[], int n, int capacity) {
int sorted[MAX];
for (int i = 0; i &lt; n; i++)
sorted[i] = weight[i];
// Sort in decreasing order
qsort(sorted, n, sizeof(int), compare);
firstFit(sorted, n, capacity);
printf(&quot;First Fit Decreasing applied.\n&quot;);
}

void bestFit(int weight[], int n, int capacity) {
int bin_rem[MAX];
int binsUsed = 0;
for (int i = 0; i &lt; n; i++) {
int min_space = capacity + 1;
int bestIndex = -1;
for (int j = 0; j &lt; binsUsed; j++) {
if (bin_rem[j] &gt;= weight[i] &amp;&amp;
bin_rem[j] - weight[i] &lt; min_space) {

bestIndex = j;
min_space = bin_rem[j] - weight[i];
}
}
if (bestIndex != -1) {
bin_rem[bestIndex] -= weight[i];
} else {
bin_rem[binsUsed] = capacity - weight[i];
binsUsed++;
}
}
printf(&quot;\nBest Fit:\n&quot;);
printBins(bin_rem, binsUsed);
}

int main() {
int n, capacity;
int weight[MAX];
printf(&quot;Enter number of items: &quot;);
scanf(&quot;%d&quot;, &amp;n);
printf(&quot;Enter bin capacity: &quot;);
scanf(&quot;%d&quot;, &amp;capacity);
printf(&quot;Enter item weights:\n&quot;);
for (int i = 0; i &lt; n; i++)
scanf(&quot;%d&quot;, &amp;weight[i]);
firstFit(weight, n, capacity);
firstFitDecreasing(weight, n, capacity);

bestFit(weight, n, capacity);
return 0;
}
