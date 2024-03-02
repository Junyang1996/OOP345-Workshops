#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

class PasswordValidator
{
private:
    std::unordered_set<char> validChars;
    std::unordered_set<char> invalidChars;
    bool requireLowerCase;
    bool requireUpperCase;
    bool requireNumber;
    int minLength;

public:
    PasswordValidator(const std::unordered_set<char> &valid, const std::unordered_set<char> &invalid,
                      bool requireLower = true, bool requireUpper = true, bool requireNum = false, int minLen = 0)
        : validChars(valid), invalidChars(invalid), requireLowerCase(requireLower),
          requireUpperCase(requireUpper), requireNumber(requireNum), minLength(minLen) {}

    bool operator()(const std::string &password) const
    {
        if (password.length() < minLength)
        {
            return false;
        }

        bool hasLowerCase = false;
        bool hasUpperCase = false;
        bool hasNumber = false;
        bool hasValidChar = false;

        for (char c : password)
        {
            if (std::islower(c))
            {
                hasLowerCase = true;
            }
            else if (std::isupper(c))
            {
                hasUpperCase = true;
            }
            else if (std::isdigit(c))
            {
                hasNumber = true;
            }
            if (validChars.find(c) != validChars.end())
            {
                hasValidChar = true;
            }
            if (invalidChars.find(c) != invalidChars.end())
            {
                return false;
            }
        }

        return (!requireLowerCase || hasLowerCase) &&
               (!requireUpperCase || hasUpperCase) &&
               (!requireNumber || hasNumber) &&
               hasValidChar;
    }
};

int main()
{
    // Define sets of valid and invalid characters
    std::unordered_set<char> validChars = {'!', '#', '$', '%', '^', '&', '*', '(', ')'};
    std::unordered_set<char> invalidChars = {' ', '\n', '\t'};

    // Create a PasswordValidator functor instance
    PasswordValidator validator(validChars, invalidChars, true, true, true, 8);

    // Test the functor with passwords
    std::cout << "Password 'P@ssw0rd': " << std::boolalpha << validator("P@ssw0rd") << std::endl;
    std::cout << "Password 'weak': " << std::boolalpha << validator("weak") << std::endl;
    std::cout << "Password 'NoNumber': " << std::boolalpha << validator("NoNumber") << std::endl;

    return 0;
}
