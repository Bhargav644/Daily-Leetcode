int minimumLength(string s)
{
    int i = 0, j = s.length() - 1;
    char prevChar = 'l';
    while (i < j)
    {
        if (s[i] == s[j])
        {
            prevChar = s[i];
            i++;
            j--;
        }
        else if (s[i] == prevChar)
        {
            i++;
        }
        else if (s[j] == prevChar)
        {
            j--;
        }
        else
        {
            break;
        }
    }
    if (i == j && prevChar == s[i])
    {
        return 0;
    }
    return i == j ? 1 : j - i + 1;
}