#include <stdio.h>
// Structure to store item details
struct Item {
int profit;
int weight;
float ratio;
};
int main() {
int n, capacity;
float totalProfit = 0;
printf(&quot;Enter number of items: &quot;);
scanf(&quot;%d&quot;, &amp;n);
struct Item item[n];
printf(&quot;Enter profit and weight of each item:\n&quot;);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d %d&quot;, &amp;item[i].profit, &amp;item[i].weight);
item[i].ratio = (float)item[i].profit / item[i].weight;
}
printf(&quot;Enter knapsack capacity: &quot;);
scanf(&quot;%d&quot;, &amp;capacity);
// Sort items in decreasing order of profit/weight ratio
for (int i = 0; i &lt; n - 1; i++) {
for (int j = i + 1; j &lt; n; j++) {

if (item[i].ratio &lt; item[j].ratio) {
struct Item temp = item[i];
item[i] = item[j];
item[j] = temp;
}
}
}
printf(&quot;\nItems selected:\n&quot;);
for (int i = 0; i &lt; n; i++) {
if (capacity &gt;= item[i].weight) {
// Take full item
printf(&quot;Item with profit %d and weight %d taken fully\n&quot;,
item[i].profit, item[i].weight);
totalProfit += item[i].profit;
capacity -= item[i].weight;
} else {
// Take fraction of item
printf(&quot;Item with profit %d and weight %d taken partially\n&quot;,
item[i].profit, item[i].weight);
totalProfit += item[i].profit * ((float)capacity / item[i].weight);
break;
}
}
printf(&quot;\nMaximum Profit = %.2f\n&quot;, totalProfit);
return 0;
}
