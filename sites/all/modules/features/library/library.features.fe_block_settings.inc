<?php
/**
 * @file
 * library.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function library_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-features'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'features',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-librarian-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-librarian-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
      'librarian' => 4,
    ),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -7,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-user'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-user',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
      'member' => 5,
    ),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -6,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
