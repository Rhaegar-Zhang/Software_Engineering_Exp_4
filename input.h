class IntInput
{
public:

private:
    int min_value, max_value;
protected:
};


class StringInput
{
public:
    int min_length, max_length;
private:

protected:
};

class CharInput : public StringInput
{
public:
private:

protected:
};
