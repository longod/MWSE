-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- A 3 by 3 matrix. You can perform following arithmetic with this type: `+`, `-`, `*`, and `==`.
--- @class tes3matrix33
--- @field x tes3vector3 The first row of the matrix.
--- @field y tes3vector3 The second row of the matrix.
--- @field z tes3vector3 The third row of the matrix.
tes3matrix33 = {}

--- Creates a new 3 by 3 matrix from 3 provided vectors or 9 numbers. Creates an empty matrix if nothing is provided.
--- @param x0 number? *Default*: `0`. No description yet available.
--- @param y0 number? *Default*: `0`. No description yet available.
--- @param z0 number? *Default*: `0`. No description yet available.
--- @param x1 number? *Default*: `0`. No description yet available.
--- @param y1 number? *Default*: `0`. No description yet available.
--- @param z1 number? *Default*: `0`. No description yet available.
--- @param x2 number? *Default*: `0`. No description yet available.
--- @param y2 number? *Default*: `0`. No description yet available.
--- @param z2 number? *Default*: `0`. No description yet available.
--- @param x tes3vector3? *Optional*. No description yet available.
--- @param y tes3vector3? *Optional*. No description yet available.
--- @param z tes3vector3? *Optional*. No description yet available.
--- @return tes3matrix33 matrix No description yet available.
function tes3matrix33.new(x0, y0, z0, x1, y1, z1, x2, y2, z2, x, y, z) end

--- Creates a copy of the matrix.
--- @return tes3matrix33 result No description yet available.
function tes3matrix33:copy() end

--- Fills the matrix with values from euler coordinates.
--- @param x number No description yet available.
--- @param y number No description yet available.
--- @param z number No description yet available.
function tes3matrix33:fromEulerXYZ(x, y, z) end

--- Fills the matrix with values from euler coordinates.
--- @param z number No description yet available.
--- @param y number No description yet available.
--- @param x number No description yet available.
function tes3matrix33:fromEulerZYX(z, y, x) end

--- Fill the matrix by converting a quaternion.
--- @param quaternion niQuaternion No description yet available.
function tes3matrix33:fromQuaternion(quaternion) end

--- Inverts the matrix.
--- @return tes3matrix33 matrix No description yet available.
--- @return boolean valid No description yet available.
function tes3matrix33:invert() end

--- Reorthogonalizes the matrix.
--- @return boolean result No description yet available.
function tes3matrix33:reorthogonalize() end

--- Converts the matrix to series of rotations along each axis.
--- @return tes3vector3 vector3 No description yet available.
--- @return boolean isUnique No description yet available.
function tes3matrix33:toEulerXYZ() end

--- Converts the matrix to series of rotations along each axis.
--- @return tes3vector3 vector3 No description yet available.
--- @return boolean isUnique No description yet available.
function tes3matrix33:toEulerZYX() end

--- Converts the matrix to the identity matrix's values.
function tes3matrix33:toIdentity() end

--- Convert the matrix into a quaternion.
--- @return niQuaternion result No description yet available.
function tes3matrix33:toQuaternion() end

--- Makes this matrix a rotation matrix with provided axis-angle rotation parameters.
--- @param angle number No description yet available.
--- @param x number No description yet available.
--- @param y number No description yet available.
--- @param z number No description yet available.
function tes3matrix33:toRotation(angle, x, y, z) end

--- Fills this matrix with the values needed to rotate a 3-by-1 vector or 3-by-N matrix of vectors around the X axis by `x` degrees. For the rotation matrix A and vector v, the rotated vector is given by A * v.
--- @param x number No description yet available.
function tes3matrix33:toRotationX(x) end

--- Fills this matrix with the values needed to rotate a 3-by-1 vector or 3-by-N matrix of vectors around the Y axis by `y` degrees. For the rotation matrix A and vector v, the rotated vector is given by A * v.
--- @param y number No description yet available.
function tes3matrix33:toRotationY(y) end

--- Fills this matrix with the values needed to rotate a 3-by-1 vector or 3-by-N matrix of vectors around the Z axis by `x` degrees. For the rotation matrix A and vector v, the rotated vector is given by A * v.
--- @param z number No description yet available.
function tes3matrix33:toRotationZ(z) end

--- Zeroes out all values in the matrix.
function tes3matrix33:toZero() end

--- No description yet available.
--- @return tes3matrix33 result No description yet available.
function tes3matrix33:transpose() end

