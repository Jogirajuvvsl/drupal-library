<?php
/**
 * @file
 * library.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function library_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'create book content'.
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create issue content'.
  $permissions['create issue content'] = array(
    'name' => 'create issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create transaction content'.
  $permissions['create transaction content'] = array(
    'name' => 'create transaction content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any book content'.
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any issue content'.
  $permissions['delete any issue content'] = array(
    'name' => 'delete any issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any transaction content'.
  $permissions['delete any transaction content'] = array(
    'name' => 'delete any transaction content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own book content'.
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own issue content'.
  $permissions['delete own issue content'] = array(
    'name' => 'delete own issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own transaction content'.
  $permissions['delete own transaction content'] = array(
    'name' => 'delete own transaction content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any book content'.
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any issue content'.
  $permissions['edit any issue content'] = array(
    'name' => 'edit any issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any transaction content'.
  $permissions['edit any transaction content'] = array(
    'name' => 'edit any transaction content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own book content'.
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own issue content'.
  $permissions['edit own issue content'] = array(
    'name' => 'edit own issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own transaction content'.
  $permissions['edit own transaction content'] = array(
    'name' => 'edit own transaction content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'fine form'.
  $permissions['fine form'] = array(
    'name' => 'fine form',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'custom_library',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
      'member' => 'member',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'use Rules component rules_add_stock'.
  $permissions['use Rules component rules_add_stock'] = array(
    'name' => 'use Rules component rules_add_stock',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_delete_stock'.
  $permissions['use Rules component rules_delete_stock'] = array(
    'name' => 'use Rules component rules_delete_stock',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_issue'.
  $permissions['use Rules component rules_issue'] = array(
    'name' => 'use Rules component rules_issue',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'librarian' => 'librarian',
      'member' => 'member',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_issue_fields'.
  $permissions['use Rules component rules_issue_fields'] = array(
    'name' => 'use Rules component rules_issue_fields',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_issue_librarian_1'.
  $permissions['use Rules component rules_issue_librarian_1'] = array(
    'name' => 'use Rules component rules_issue_librarian_1',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_return'.
  $permissions['use Rules component rules_return'] = array(
    'name' => 'use Rules component rules_return',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_return_by_librarian'.
  $permissions['use Rules component rules_return_by_librarian'] = array(
    'name' => 'use Rules component rules_return_by_librarian',
    'roles' => array(
      'administrator' => 'administrator',
      'librarian' => 'librarian',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  return $permissions;
}
