#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print a section label inside tests */
#define TEST_CASE(label) do { \
    printf("  - %s\n", (label)); \
} while (0)

/* Run a test function that returns 0 on success, nonzero on failure */
#define RUN_TEST(fn) do { \
    printf("== %s ==\n", #fn); \
    int _res = (fn)(); \
    if (_res == 0) printf("[ALL PASS]\n\n", #fn); \
    else           printf("[FAIL] %s (code=%d)\n\n", #fn, _res); \
} while (0)

/* Assertions that always print what happened */
#define ASSERT_EQ_INT(exp, got) do { \
    int _e = (int)(exp), _g = (int)(got); \
    if (_e != _g) { \
        fprintf(stderr, "    FAIL INT: expected=%d got=%d\n\n", _e, _g); \
        return 1; \
    } else { \
        printf("    ok   INT: %d == %d\n\n", _g, _e); \
    } \
} while (0)

#define ASSERT_EQ_SIZE(exp, got) do { \
    size_t _e = (size_t)(exp), _g = (size_t)(got); \
    if (_e != _g) { \
        fprintf(stderr, "    FAIL SIZE: expected=%zu got=%zu\n\n", _e, _g); \
        return 1; \
    } else { \
        printf("    ok   SIZE: %zu == %zu\n\n", _g, _e); \
    } \
} while (0)

#define ASSERT_EQ_STR(exp, got) do { \
    const char *_e = (exp), *_g = (got); \
    if (strcmp(_e, _g) != 0) { \
        fprintf(stderr, "    FAIL STR:\n      expected: \"%s\"\n      got:      \"%s\"\n\n", _e, _g); \
        return 1; \
    } else { \
        printf("    ok   STR: \"%s\"\n\n", _g); \
    } \
} while (0)

#define ASSERT_TRUE(cond) do { \
    if (!(cond)) { \
        fprintf(stderr, "    FAIL TRUE: %s\n\n", #cond); \
        return 1; \
    } else { \
        printf("    ok   TRUE: %s\n\n", #cond); \
    } \
} while (0)

#define ASSERT_FALSE(cond) do { \
    if ((cond)) { \
        fprintf(stderr, "    FAIL FALSE: %s\n\n", #cond); \
        return 1; \
    } else { \
        printf("    ok   FALSE: %s\n\n", #cond); \
    } \
} while (0)

#endif
