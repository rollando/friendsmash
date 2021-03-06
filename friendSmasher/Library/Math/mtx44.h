#ifndef FRIENDSMASHER_MTX44
#define FRIENDSMASHER_MTX44

#include "debug.h"

namespace FriendSmasher
{
namespace Math
{
	class mtx44
	{
	public:

		mtx44(void);

		mtx44(const float aa, const float ab, const float ac, const float ad,
			  const float ba, const float bb, const float bc, const float bd,
			  const float ca, const float cb, const float cc, const float cd,
			  const float da, const float db, const float dc, const float dd);

		~mtx44(void) {};

		bool operator == (const mtx44 &rhs) const;
		bool operator != (const mtx44 &rhs) const;
		mtx44 operator * (const mtx44 &rhs) const;

		inline float& operator()(int row, int col)
		{
			FBAssert(row >= 0);
			FBAssert(row <= 3);
			FBAssert(col >= 0);
			FBAssert(col <= 3);
			return m_mat[row][col];
		}
		
		inline float operator()(int row, int col) const
		{
			FBAssert(row >= 0);
			FBAssert(row <= 3);
			FBAssert(col >= 0);
			FBAssert(col <= 3);
			return m_mat[row][col];
		}

		inline float* operator[](int row)
		{
			FBAssert(row >= 0);
			FBAssert(row <= 3);
			return m_mat[row];
		}
		
		inline const float* operator[](int row) const
		{
			FBAssert(row >= 0);
			FBAssert(row <= 3);
			return m_mat[row];
		}

		static mtx44 identity;

	private:
		float m_mat[4][4];
	};
}
}

#endif // namespace FriendSmasher_MTX44