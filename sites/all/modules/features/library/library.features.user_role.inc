<?php
/**
 * @file
 * library.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function library_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: librarian.
  $roles['librarian'] = array(
    'name' => 'librarian',
    'weight' => 3,
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 4,
  );

  return $roles;
}
