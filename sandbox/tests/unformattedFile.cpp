#include <string>

template <typename T, 
int N>
struct Foo {
  T mData[N];

  Foo<T, N> operator+(const Foo<T, N> &other) const {}

  Foo<T, N> bar(const Foo<T, N> &other,
                float t) const {}
};

template <typename T,  
          int N>       
struct Foo {
  T mData[N];

  Foo<T, N> operator+(const Foo<T, N> &other) const {  
  }

  Foo<T, N> bar(const Foo<T, N> &other,  
                float t) const {         
  }
};

enum State { IDLE_SOMETHING, RUNNING, DONE };

template <typename T,
          typename U,
          typename V,
          typename W,
          typename X,
          typename Y,
          typename Z>
struct SomeLongTemplate {
  T mfirst;
  U msecond;
  V mthird;
  W mfourth;
  X mfifth;
  Y msixth;
  Z mseventh;

  SomeLongTemplate(const T &t,
                   const U &u,
                   const V &v,
                   const W &w,
                   const X &x,
                   const Y &y,
                   const Z &z)
      : mfirst(t),
        msecond(u),
        mthird(v),
        mfourth(w),
        mfifth(x),
        msixth(y),
        mseventh(z) {}
};

template <typename T, typename U>
struct Pair {
 public:
  T mfirst;
  U msecond;

  static float thisIsAStatic;

  Pair(const T &t,
       const U &u)
      : mfirst(t),
        msecond(u) {}

  template <typename V, typename W>
  Pair(const Pair<Pair<V, W>, Pair<T, U>> &p)
      : mfirst(p.mfirst),
        msecond(p.msecond) {}

  void foo(float a,
           float b,
           float c) {
    if (a > b) {
      a = b;
    } else {
      a = c;
    }

    State someState = IDLE_SOMETHING;
    switch (someState) {
      case IDLE_SOMETHING: {
        foo(0.0f, 1.0f, 2.0f);
      } break;
      case RUNNING:
        break;
      case DONE:
        break;
      default:
        break;
    }

    bool superLongConditionNameYeahA = true;
    bool superLongConditionNameYeahB = false;
    bool superLongConditionNameYeahC = true;
    bool superLongConditionNameYeahD = false;
    bool superLongConditionNameYeahE = true;

    if ((superLongConditionNameYeahA && superLongConditionNameYeahB) &&
        (superLongConditionNameYeahC && superLongConditionNameYeahD) &&
        superLongConditionNameYeahE) {
      a = b;
    } else {
      a = c;
    }

    bool someSuperLongVariableAssignment =
        superLongConditionNameYeahA && superLongConditionNameYeahB &&
        superLongConditionNameYeahC && superLongConditionNameYeahD &&
        superLongConditionNameYeahE;

    auto value = static_cast<int>(someSuperLongVariableAssignment);
  }
};

typedef Pair<float, int> PairFiT;

PairFiT gPair(1.0f,
              2);

class Foo {
 public:
  Foo() {}
  void bar(int x,
           int y,
           const int *z,
           std::string str) const {
    auto f = x + y;
    x = (*z) * x;
    Pair<float, int> p(1.0f, 2);
    if (x > 0) {
      y += x;
    } else {
      y -= x;
    }

    for (int i = 0; i < 10; ++i) {
      y += i;
    }

    p.foo(0.0f, 1.0f, 2.0f);
  }
};

void helperfunction(int a,
                    int b) {
  if (a == b) {
    return;
  } else {
    a++;
    b--;
  }
}

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MACRO_NAME_TEST

static const int SENTINEL = -1;
static std::string globalName;