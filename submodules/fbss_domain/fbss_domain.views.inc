<?php

/**
 * @file
 *   Views integration for the Statuses Domain Access module.
 */

/**
 * Implements hook_views_data().
 */
function fbss_domain_views_data() {
  // Basic table information.
  $data['fbss_domain']['table']['join'] = array(
    'statuses' => array(
      'left_field' => 'sid',
      'field' => 'sid',
      'type' => 'LEFT',
    ),
  );
  $data['domain']['table']['join'] = array(
    'fbss_domain' => array(
      'left_field' => 'domain_id',
      'field' => 'domain_id',
      'type' => 'INNER',
    ),
  );
  $data['fbss_domain']['domain_id'] = array(
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'domain',
      'base field' => 'domain_id',
      'group' => t('Statuses'),
      'title' => t('Statuses Domain'),
      'label' => t('Domain from status'),
      'help' => t('Get the domain a status is associated with.'),
    ),
  );
  return $data;
}
