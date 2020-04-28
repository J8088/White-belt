//Имена-фамилии -2!!!!!!!!
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using  namespace std;

struct Name
{
    string fn;
    string ln;
};

string History(vector<string> v)
{
    if (v.size() == 0)
        return " ";
    string res = " (";
    for (int i = v.size() - 1; i >= 0; --i) {
        res = res + v[i] + ", ";
    }
    res.resize(res.size() - 2);
    res += ") ";
    return res;
}

string History2(vector<string> v)
{
    if (v.size() == 0)
        return "";
    string res = " (";
    for (int i = v.size() - 1; i >= 0; --i) {
        res = res + v[i] + ", ";
    }
    res.resize(res.size() - 2);
    res += ")";
    return res;
}

class Person {
private:
    map<int, Name> n;
    int bthy;
public:
    Person(string nm, string lnm, int y)
    {
        bthy = y;
        n[bthy].fn = nm;
        n[bthy].ln = lnm;
    }
  void ChangeFirstName(int year, const string& first_name) {
      if (year < bthy) return;
    n[year].fn = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
      if (year < bthy) return;
      n[year].ln = last_name;
  }
  string GetFullNameWithHistory(int year) const{
      if (year < bthy) return "No person";
      string fnm = "";
      string lnm = "";
      vector<string> hn;
      vector<string> hln;
      int i = 0;
      bool fl = 0;
      for (const auto& a : n)
      {
          if ((fl == 1) && (year <  a.first))
          {
              if ((fnm != "") && (lnm == ""))
                  return fnm + History(hn) + "with unknown last name";
              if ((fnm == "") && (lnm != ""))
                  return lnm + History(hln)+ "with unknown first name";
              if ((fnm != "") && (lnm != ""))
                  return fnm + History(hn) + lnm + History2(hln);
          }
          i++;
          if (a.second.fn != "")
          {
              if (fnm == "")
                  fnm = a.second.fn;
              if (fnm != a.second.fn)
              {
                  hn.push_back(fnm);
                  fnm = a.second.fn;
              }
          }
          if (a.second.ln != "")
          {
              if (lnm == "")
                  lnm = a.second.ln;
              if (lnm != a.second.ln)
              {
                  hln.push_back(lnm);
                  lnm = a.second.ln;
              }
          }
          if (year <  a.first) continue;
          if (year == a.first)
          {
              if ((fnm != "") && (lnm == ""))
                  return fnm + History(hn) + "with unknown last name";
              if ((fnm == "") && (lnm != ""))
                  return lnm + History(hln)+ "with unknown first name";
              if ((fnm != "") && (lnm != ""))
                  return fnm + History(hn) + lnm + History2(hln);
          }
          if (year > a.first)
          {
              fl = 1;
              if  (i != n.size()) continue;
              if ((fnm != "") && (lnm == ""))
                  return fnm + History(hn) + "with unknown last name";
              if ((fnm == "") && (lnm != ""))
                  return lnm + History(hln)+ "with unknown first name";
              if ((fnm != "") && (lnm != ""))
                  return fnm + History(hn) + lnm + History2(hln);
          }
      }
      return "Incognito";
  }

    string GetFullName(int year) const{
        if (year < bthy) return "No person";
        string fnm = "";
        string lnm = "";
        int i = 0;
        bool fl = 0;
        for (const auto& a : n)
        {
            if ((fl == 1) && (year <  a.first))
            {
                if ((fnm != "") && (lnm == ""))
                    return fnm + " with unknown last name";
                if ((fnm == "") && (lnm != ""))
                    return lnm + " with unknown first name";
                if ((fnm != "") && (lnm != ""))
                    return fnm + " " + lnm;
            }
            i++;
            if (a.second.fn != "") fnm = a.second.fn;
            if (a.second.ln != "") lnm = a.second.ln;
            if (year <  a.first) continue;
            if (year == a.first)
            {
                if ((fnm != "") && (lnm == ""))
                    return fnm + " with unknown last name";
                if ((fnm == "") && (lnm != ""))
                    return lnm + " with unknown first name";
                if ((fnm != "") && (lnm != ""))
                    return fnm + " " + lnm;
            }
            if (year > a.first)
            {
                fl = 1;
                if  (i != n.size()) continue;
                if ((fnm != "") && (lnm == ""))
                    return fnm + " with unknown last name";
                if ((fnm == "") && (lnm != ""))
                    return lnm + " with unknown first name";
                if ((fnm != "") && (lnm != ""))
                    return fnm +  " " + lnm;
            }
        }
        return "Incognito";
    }
};
