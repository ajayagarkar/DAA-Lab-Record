#include <stdio.h>
int matrix[25][25], visited_cities[10], limit, cost = 0;
int tsp(int c)
{
int count, nearest_city = 999;
int minimum = 999, temp;
for(count = 0; count &lt; limit; count++)
{
if((matrix[c][count] != 0) &amp;&amp; (visited_cities[count] == 0))
{
if(matrix[c][count] &lt; minimum)
{
minimum = matrix[count][0] + matrix[c][count];
}
temp = matrix[c][count];
nearest_city = count;
}
}
if(minimum != 999)
{
cost = cost + temp;
}
return nearest_city;
}
void minimum_cost(int city)
{
int nearest_city;
visited_cities[city] = 1;
printf(&quot;%d &quot;, city + 1);
nearest_city = tsp(city);
if(nearest_city == 999)
{
nearest_city = 0;

printf(&quot;%d&quot;, nearest_city + 1);
cost = cost + matrix[city][nearest_city];
return;
}
minimum_cost(nearest_city);
}
int main()
{
int i, j;
printf(&quot;Enter Total Number of Cities:\t&quot;);
scanf(&quot;%d&quot;, &amp;limit);
printf(&quot;\nEnter Cost Matrix\n&quot;);
for(i = 0; i &lt; limit; i++)
{
printf(&quot;\nEnter %d Elements in Row[%d]\n&quot;, limit, i + 1);
for(j = 0; j &lt; limit; j++)
{
scanf(&quot;%d&quot;, &amp;matrix[i][j]);
}
visited_cities[i] = 0;
}
printf(&quot;\nEntered Cost Matrix\n&quot;);
for(i = 0; i &lt; limit; i++)
{
printf(&quot;\n&quot;);
for(j = 0; j &lt; limit; j++)
{
printf(&quot;%d &quot;, matrix[i][j]);
}
}
printf(&quot;\n\nPath:\t&quot;);
minimum_cost(0);
printf(&quot;\n\nMinimum Cost: \t&quot;);
printf(&quot;%d\n&quot;, cost);
return 0;
}
