#include "dtkMatrixOP.h"

#ifdef DTK_GLM
namespace dtk {
	dtkDouble2 operator*(const dtkMatrix22& a, const dtkDouble2& b) {
		return { a[0][0] * b[0] + a[0][1] * b[1],
				a[1][0] * b[0] + a[1][1] * b[1] };
	}

	dtkMatrix22 operator*(const dtkMatrix22& a, const dtkMatrix22& b) {
		dtkMatrix22 ret();
		return dtkMatrix22{ a[0][0] * b[0][0] + a[0][1] * b[1][0],
				a[0][0] * b[0][1] + a[0][1] * b[1][1],
			a[1][0] * b[0][0] + a[1][1] * b[1][0],
				a[1][0] * b[0][1] + a[1][1] * b[1][1] };
	}

	void operator*=(dtkMatrix22& a, const dtkMatrix22& b) {
		a = a * b;
	}

	dtkMatrix22 operator*(const dtkMatrix22& a, double b) {
		return dtkMatrix22{ a[0].x * b, a[0].y * b,
				a[1].x * b, a[1].y * b };
	}

	dtkMatrix22 operator*(double a, const dtkMatrix22& b) {
		return b * a;
	}

	dtkMatrix22 rotate(double theta) {
		const auto _sin = std::sin(theta);
		const auto _cos = std::cos(theta);
		return dtkMatrix22{ _cos, -_sin, _sin, _cos };
	}
}

#endif