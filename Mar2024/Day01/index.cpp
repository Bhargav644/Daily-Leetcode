string maximumOddBinaryNumber(string s)
{
    int n = s.length() - 1;
    int count = 0;
    for (auto i : s)
    {
        if (i == '1')
            count++;
    }
    string ans = "";
    while (n--)
    {
        if (count > 1)
        {
            ans = ans + '1';
            count--;
        }
        else
        {
            ans = ans + '0';
        }
    }
    ans = ans + (count == 1 ? '1' : '0');
    return ans;
}